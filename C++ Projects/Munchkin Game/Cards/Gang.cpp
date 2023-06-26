//
// Created by Amit on 19/06/2022.
//

#include "Gang.h"
#include "Vampire.h"

using std::unique_ptr;
using std::deque;

Gang::Gang() :
        Card("Gang")
{}

void Gang::applyEncounter(std::unique_ptr<Player> &player)
{
    bool playerWon = true;
    for (int i = 0 ; i < m_numOfMonsters ; ++i) {
        if ((*player).getAttackStrength() >= m_gangCards.front()->getMonsterForce()) {
            player->addCoins(m_gangCards.front()->getMonsterLoot());
            m_gangCards.push_back(move(m_gangCards.front()));
            m_gangCards.pop_front();
        } else {
            playerWon = false;
            for (int j = i ; j < m_numOfMonsters ; ++j) {
                player->damage(m_gangCards.front()->getMonsterDamage());
                if (checkSpecialCard(m_gangCards.front())) {
                    player->buff(VAMPIRE_FORCE_STEAL);
                }
                printLossBattle(player->getName(), (m_gangCards.front())->getMonsterName());
                m_gangCards.push_back(move(m_gangCards.front()));
                m_gangCards.pop_front();
            }
            break;
        }
    }
    if (playerWon) {
        printWinBattle(player->getName(), m_name);
        player->levelUp();
    }
}

void Gang::printCard(std::ostream &os) const
{
    for (const unique_ptr<Battle> &monster : m_gangCards) {
        printCardDetails(os, monster->getName());
    }
}

bool Gang::checkSpecialCard(std::unique_ptr<Battle> &ptrToCard)
{
    try {
        dynamic_cast<Vampire &>(*ptrToCard);
    }
    catch (const std::bad_cast &e) {
        return false;
    }
    return true;
}

Gang::Gang(const Gang &gangToCopy) :
        Card(gangToCopy.getName())
{
    for (const unique_ptr<Battle> &monster : gangToCopy.m_gangCards) {
        m_gangCards.push_back(monster->clone());
    }
}

Gang &Gang::operator=(const Gang &gangToCopy)
{
    if (this == &gangToCopy) {
        return *this;
    }
    for (int i = 0 ; i < m_numOfMonsters ; ++i) {
        m_gangCards.pop_back();
    }
    for (const unique_ptr<Battle> &monster : gangToCopy.m_gangCards) {
        m_gangCards.push_back(monster->clone());
    }
    return *this;
}
