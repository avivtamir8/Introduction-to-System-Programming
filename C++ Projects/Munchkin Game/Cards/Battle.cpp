//
// Created by Amit on 08/06/2022.
//

#include "Battle.h"

#include <utility>

using std::string;

Battle::Battle(const string& name, int loot, int monsterForce, int damageToPlayer) :
        Card(std::move(name)),
        m_loot(loot),
        m_monsterForce(monsterForce),
        m_damageToPlayer(damageToPlayer)
{}

bool Battle::checkWin(const Player &player) const
{
    return m_monsterForce <= player.getAttackStrength();
}

int Battle::getMonsterForce() const
{
    return m_monsterForce;
}

int Battle::getMonsterDamage() const
{
    return m_damageToPlayer;
}

int Battle::getMonsterLoot() const
{
    return m_loot;
}

std::string Battle::getMonsterName() const
{
    return m_name;
}

