//
// Created by Amit on 08/06/2022.
//

#include "Vampire.h"
using std::unique_ptr;

Vampire::Vampire() :
        Battle("Vampire", VAMPIRE_LOOT, VAMPIRE_FORCE, VAMPIRE_DAMAGE)
{}

void Vampire::applyEncounter(std::unique_ptr<Player> &player)
{
    if (checkWin(*player)) {
        player->addCoins(VAMPIRE_LOOT);
        player->levelUp();
        printWinBattle(player->getName(), m_name);
    } else {
        player->buff(VAMPIRE_FORCE_STEAL);
        player->damage(m_damageToPlayer);
        printLossBattle(player->getName(), m_name);
    }
}

void Vampire::printCard(std::ostream &os) const
{
    printMonsterDetails(os, m_monsterForce, m_damageToPlayer, m_loot, false);
}

std::unique_ptr<Battle> Vampire::clone() const
{
    unique_ptr<Battle> newVampire(new Vampire(*this)) ;
    return newVampire;
}
