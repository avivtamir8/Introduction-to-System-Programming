//
// Created by Amit on 11/06/2022.
//

#include "Mtmchkin.h"

using std::string;
using std::getline;
using std::unique_ptr;
using std::move;
using std::cin;

Mtmchkin::Mtmchkin(const std::string &fileName)
{
    printStartGameMessage();
    std::ifstream infile(fileName);
    if (!infile) {
        throw DeckFileNotFound();
    }
    if (createCardQueue(infile) < MIN_NUM_OF_CARDS) {
        throw DeckFileInvalidSize();
    }
    int teamSize;
    bool correctTeamSize = false;
    while (!correctTeamSize) {
        printEnterTeamSizeMessage();
        correctTeamSize = getTeamSize(teamSize);
    }
    createPlayerDeque(teamSize);
}

bool Mtmchkin::getTeamSize(int &teamSize)
{
    string teamSizeString;
    try {
        getline(std::cin, teamSizeString);
        teamSize = std::stoi(teamSizeString);
        if (teamSize < MIN_TEAM_SIZE || teamSize > MAX_TEAM_SIZE) {
            throw InvalidTeamSize();
        }
    }
    catch (const std::invalid_argument &e) {
        printInvalidTeamSize();
        return false;
    }
    catch (const InvalidTeamSize &e) {
        printInvalidTeamSize();
        return false;
    }
    return true;
}

Mtmchkin::stringCodeCard Mtmchkin::mapCards(const string &inString)
{
    if (inString == "Dragon") {
        return eDragon;
    }
    if (inString == "Vampire") {
        return eVampire;
    }
    if (inString == "Goblin") {
        return eGoblin;
    }
    if (inString == "Fairy") {
        return eFairy;
    }
    if (inString == "Barfight") {
        return eBarfight;
    }
    if (inString == "Pitfall") {
        return ePitfall;
    }
    if (inString == "Treasure") {
        return eTreasure;
    }
    if (inString == "Merchant") {
        return eMerchant;
    }
    if (inString == "Gang") {
        return eStartGang;
    }
    if (inString == "EndGang")
        return eEndGang;
    return eNone;
}

Mtmchkin::stringCodeJob Mtmchkin::mapJobs(const string &inString)
{
    if (inString == "Rogue") {
        return eRogue;
    }
    if (inString == "Wizard") {
        return eWizard;
    }
    if (inString == "Fighter") {
        return eFighter;
    }
    return eNull;
}

int Mtmchkin::createCardQueue(std::ifstream &file)
{
    string nextLine;
    int lineNum = STARTING_LINE;
    int linesToAdd;
    int monsterAmount = 0;
    while (getline(file, nextLine)) {
        linesToAdd = createSpecificCard(nextLine, lineNum, file);
        if (linesToAdd < NO_END_GANG) {
            lineNum -= linesToAdd;
            throw DeckFileFormatError(lineNum);
        }
        lineNum += linesToAdd;
        monsterAmount++;
    }
    return monsterAmount;
}

void Mtmchkin::createPlayerDeque(int partySize)
{
    string name, job;
    for (int i = 0 ; i < partySize ; i++) {
        printInsertPlayerMessage();
        getline(cin, name, ' ');
        while (!checkIfNameValid(name)) {
            getline(cin, job);
            printInvalidName();
            getline(cin, name, ' ');
        }
        getline(cin, job);
        while (mapJobs(job) == eNull) {
            printInvalidClass();
            getline(cin, name, ' ');
            while (!checkIfNameValid(name)) {
                getline(cin, job);
                printInvalidName();
                getline(cin, name, ' ');
            }
            getline(cin, job);
        }
        createSpecificPlayer(job, name);
    }
}

bool Mtmchkin::checkIfNameValid(const std::string &name)
{
    for (char letter : name) {
        if (!isalpha(letter)) {
            return false;
        }
    }
    if (name.size() > MAX_NAME_SIZE) {
        return false;
    }
    return true;
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_numOfRounds;
}

void Mtmchkin::playRound()
{
    m_numOfRounds++;
    printRoundStartMessage(m_numOfRounds);
    int partySize = m_leaderboard.m_currentPlayers.size();
    for (int i = 0 ; i < partySize ; ++i) {
        printTurnStartMessage(m_leaderboard.m_currentPlayers.front()->getName());
        m_cards.front()->applyEncounter(m_leaderboard.m_currentPlayers.front());
        unique_ptr<Card> tempCard = move(m_cards.front());
        m_cards.pop();
        m_cards.push(move(tempCard));
        int currentPlayerCondition = playerCondition(*m_leaderboard.m_currentPlayers.front());
        switch (currentPlayerCondition) {
            case PLAYER_ALIVE: {
                unique_ptr<Player> tempPlayer = move(m_leaderboard.m_currentPlayers.front());
                m_leaderboard.m_currentPlayers.pop_front();
                m_leaderboard.m_currentPlayers.push_back(move(tempPlayer));
                break;
            }
            case PLAYER_WON: {
                unique_ptr<Player> tempPlayer = move(m_leaderboard.m_currentPlayers.front());
                m_leaderboard.m_currentPlayers.pop_front();
                m_leaderboard.m_winners.push_back(move(tempPlayer));
                break;
            }
            case PLAYER_DEAD: {
                unique_ptr<Player> tempPlayer = move(m_leaderboard.m_currentPlayers.front());
                m_leaderboard.m_currentPlayers.pop_front();
                m_leaderboard.m_losers.push_front(move(tempPlayer));
                break;
            }
        }
    }
    if (m_leaderboard.m_currentPlayers.empty()) {
        printGameEndMessage();
    }
}

int Mtmchkin::playerCondition(const Player &player)
{
    if (player.haveWon()) {
        return PLAYER_WON;
    }
    if (player.isKnockedOut()) {
        return PLAYER_DEAD;
    }
    return PLAYER_ALIVE;
}

bool Mtmchkin::isGameOver() const
{
    if (m_leaderboard.m_currentPlayers.empty()) {
        return true;
    }
    return false;
}

void Mtmchkin::printLeaderBoard() const
{
    int ranking = 1;
    printLeaderBoardStartMessage();
    int dequeSize = m_leaderboard.m_winners.size();
    for (int i = 0 ; i < dequeSize ; i++) {
        printPlayerLeaderBoard(ranking, *(m_leaderboard.m_winners[i]));
        ranking++;
    }
    dequeSize = m_leaderboard.m_currentPlayers.size();
    for (int i = 0 ; i < dequeSize ; i++) {
        printPlayerLeaderBoard(ranking, *(m_leaderboard.m_currentPlayers[i]));
        ranking++;
    }
    dequeSize = m_leaderboard.m_losers.size();
    for (int i = 0 ; i < dequeSize ; i++) {
        printPlayerLeaderBoard(ranking, *(m_leaderboard.m_losers[i]));
        ranking++;
    }
}

int Mtmchkin::createSpecificCard(const std::string &nextLine, int lineNum, std::ifstream &file)
{
    switch (mapCards(nextLine)) {
        case eNone:
        case eEndGang:
            throw DeckFileFormatError(lineNum);
        case eDragon: {
            m_cards.push(move(unique_ptr<Dragon>(new Dragon)));
            return ONE_MONSTER;
        }
        case eVampire: {
            m_cards.push(move(unique_ptr<Vampire>(new Vampire)));
            return ONE_MONSTER;
        }
        case eGoblin: {
            m_cards.push(move(unique_ptr<Goblin>(new Goblin)));
            return ONE_MONSTER;
        }
        case eMerchant: {
            m_cards.push(move(unique_ptr<Merchant>(new Merchant)));
            return ONE_MONSTER;
        }
        case eTreasure: {
            m_cards.push(move(unique_ptr<Treasure>(new Treasure)));
            return ONE_MONSTER;
        }
        case ePitfall: {
            m_cards.push(move(unique_ptr<Pitfall>(new Pitfall)));
            return ONE_MONSTER;
        }
        case eBarfight: {
            m_cards.push(move(unique_ptr<Barfight>(new Barfight)));
            return ONE_MONSTER;
        }
        case eFairy: {
            m_cards.push(move(unique_ptr<Fairy>(new Fairy)));
            return ONE_MONSTER;
        }
        case eStartGang: {
            return createGang(file, lineNum);
        }
    }
    return 0;
}

int Mtmchkin::createGang(std::ifstream &file, int lineNum)
{
    string nextLine;
    int linesOfGang = 1;
    bool endOccured = false;
    unique_ptr<Gang> gang = unique_ptr<Gang>(new Gang);
    while (getline(file, nextLine)) {
        if (nextLine == "EndGang") {
            linesOfGang++;
            endOccured = true;
            break;
        }
        createSpecificCardForGang(nextLine, lineNum + linesOfGang, file, gang);
        linesOfGang++;
    }
    if (!endOccured) {
        return -linesOfGang;
    }
    m_cards.push(move(gang));
    return linesOfGang;
}

void Mtmchkin::createSpecificCardForGang(const std::string &inLine, int lineNum, std::ifstream &file,
                                         unique_ptr<Gang> &gang)
{
    switch (mapCards(inLine)) {
        case eDragon: {
            gang->m_gangCards.push_back(move(unique_ptr<Dragon>(new Dragon)));
            gang->m_numOfMonsters++;
            break;
        }
        case eVampire: {
            gang->m_gangCards.push_back(move(unique_ptr<Vampire>(new Vampire)));
            gang->m_numOfMonsters++;
            break;
        }
        case eGoblin: {
            gang->m_gangCards.push_back(move(unique_ptr<Goblin>(new Goblin)));
            gang->m_numOfMonsters++;
            break;
        }
        case eNone:
        case eStartGang:
        case eMerchant:
        case eTreasure:
        case ePitfall:
        case eBarfight:
        case eFairy:
            throw DeckFileFormatError(lineNum);
        case eEndGang:
            break;
    }
}

bool Mtmchkin::createSpecificPlayer(const string &job, const string &name)
{
    switch (mapJobs(job)) {
        case eNull: {
            printInvalidClass();
            return false;
        }
        case eFighter: {
            m_leaderboard.m_currentPlayers.push_back(unique_ptr<Fighter>(new Fighter(name)));
            return true;
        }
        case eRogue: {
            m_leaderboard.m_currentPlayers.push_back(unique_ptr<Rogue>(new Rogue(name)));
            return true;
        }
        case eWizard: {
            m_leaderboard.m_currentPlayers.push_back(unique_ptr<Wizard>(new Wizard(name)));
            return true;
        }
    }
    return false;
}





