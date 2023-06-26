#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <deque>
#include <queue>
#include <fstream>
#include <memory>
#include "Players/Player.h"
#include "Cards/Card.h"
#include "Cards/Vampire.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Gang.h"
#include "Players/Rogue.h"
#include "Players/Wizard.h"
#include "Players/Fighter.h"
#include "Exception.h"

class Mtmchkin {
private:

    static const int MAX_NAME_SIZE = 15;
    static const int STARTING_LINE = 1;
    static const int PLAYER_ALIVE = 1;
    static const int PLAYER_WON = 2;
    static const int PLAYER_DEAD = 3;
    static const int MAX_TEAM_SIZE = 6;
    static const int MIN_TEAM_SIZE = 2;
    static const int MIN_NUM_OF_CARDS = 5;
    static const int ONE_MONSTER = 1;
    static const int NO_END_GANG = 0;

    class Leaderboard {
    public:

        std::deque<std::unique_ptr<Player>> m_currentPlayers;
        std::deque<std::unique_ptr<Player>> m_winners;
        std::deque<std::unique_ptr<Player>> m_losers;

    };

    enum stringCodeCard {
        eDragon,
        eVampire,
        eGoblin,
        eMerchant,
        eBarfight,
        ePitfall,
        eFairy,
        eTreasure,
        eStartGang,
        eEndGang,
        eNone
    };

    enum stringCodeJob {
        eRogue,
        eWizard,
        eFighter,
        eNull
    };

    /*
     * Checkes if the given name is due on expectations or not.
     * @param name - gets a reference to a name to check.
     * @return
     *      bool
     */
    static bool checkIfNameValid(const std::string &name);

    /*
     * Creates the players deck.
     * @param partySize - the size of the deck that will be formed.
     * @return
     *      void
     */
    void createPlayerDeque(int partySize);

    /*
     * Creates the card Queue.
     * @param file - the names of the cards in order from file.
     * @return - the number of total cards.
     *      int
     */
    int createCardQueue(std::ifstream &file);

    /*
     * Checks the player's condition after their turn
     * @param player - the player that will be inspected.
     * @return - a number that will indicate the condition.
     *      int
     */
    static int playerCondition(const Player &player);

    /*
     * Creates the specific card wanted
     * @param inLine - the line the card appears in.
     * @param lineNum - the index of the line.
     * @param file - the file that the wanted card is in.
     * @return - a number that will indicate the condition.
     *      int
     */
    int createSpecificCard(const std::string &inLine, int lineNum, std::ifstream &file);

    /*
     * creates a card and insert it into a gang.
     * @param inLine - the line the card appears in.
     * @param lineNum - the index of the line.
     * @param file - the file that the wanted card is in.
     * @param gang - a reference to the gang.
     * @return - a number that will indicate the condition.
     *      void
     */
    static void
    createSpecificCardForGang(const std::string &inLine, int lineNum, std::ifstream &file, std::unique_ptr<Gang> &gang);

    /*
     * Creates the specific player wanted.
     * @param job - the class of the player.
     * @param name - the name of the player.
     * @return
     *      bool
     */
    bool createSpecificPlayer(const std::string &job, const std::string &name);

    /*
     * Checks which type of card to create
     * @param inString - indicates the card's type
     * @return
     *      stringCodeCard
     */
    static stringCodeCard mapCards(const std::string &inString);

    /*
    * Checks which type of player to create
    * @param inString - indicates the player's class
    * @return
    *      stringCodeJob
    */
    static stringCodeJob mapJobs(const std::string &inString);

    /*
    * Gets the team size and check if its valid
    * @param teamSize - indicates the team's size.
    * @return
    *      bool
    */
    static bool getTeamSize(int &teamSize);

    /*
    * Creates a gang
    * @param file - the file to read from.
    * @param lineNum - the line to read from.
    * @return - gang size.
    *      int
    */
    int createGang(std::ifstream &file, int lineNum);

    //Mtmchkin class members
    Leaderboard m_leaderboard;
    std::queue<std::unique_ptr<Card>> m_cards;
    int m_numOfRounds = 0;


public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);

    Mtmchkin(const Mtmchkin &game) = delete;

    Mtmchkin operator=(const Mtmchkin &game) = delete;

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;
};


#endif /* MTMCHKIN_H_ */
