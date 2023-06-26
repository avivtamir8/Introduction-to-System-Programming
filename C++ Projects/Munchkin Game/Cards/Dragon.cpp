//
// Created by Amit on 08/06/2022.
//

#include "Dragon.h"

using std::unique_ptr;

Dragon::Dragon() :
        Battle("Dragon", DRAGON_LOOT, DRAGON_FORCE, DRAGON_DAMAGE)
{}

void Dragon::applyEncounter(std::unique_ptr<Player> &player)
{
    if (checkWin(*player)) {
        player->addCoins(DRAGON_LOOT);
        player->levelUp();
        printWinBattle(player->getName(), m_name);
    } else {
        player->damage(m_damageToPlayer);
        printLossBattle(player->getName(), m_name);
    }
}

void Dragon::printCard(std::ostream &os) const
{
    printMonsterDetails(os, m_monsterForce, m_damageToPlayer, m_loot, true);
}

std::unique_ptr<Battle> Dragon::clone() const
{
    unique_ptr<Battle> newDragon(new Dragon(*this));
    return newDragon;
}
