//
// Created by Amit on 08/06/2022.
//

#include "Goblin.h"
using std::unique_ptr;

Goblin::Goblin() :
        Battle("Goblin", GOBLIN_LOOT, GOBLIN_FORCE, GOBLIN_DAMAGE)
{}

void Goblin::applyEncounter(std::unique_ptr<Player> &player)
{
    if (checkWin(*player)) {
        player->addCoins(GOBLIN_LOOT);
        player->levelUp();
        printWinBattle(player->getName(), m_name);
    } else {
        player->damage(m_damageToPlayer);
        printLossBattle(player->getName(), m_name);
    }
}

void Goblin::printCard(std::ostream &os) const
{
    printMonsterDetails(os, m_monsterForce, m_damageToPlayer, m_loot, false);
}

unique_ptr<Battle> Goblin::clone() const
{
    unique_ptr<Battle> newGoblin(new Goblin(*this)) ;
    return newGoblin;
}
