//
// Created by Amit on 08/06/2022.
//

#include "Fighter.h"

Fighter::Fighter(const std::string &name) :
        Player(name, "Fighter")
{}

int Fighter::getAttackStrength() const
{
    return m_level + (m_force * DOUBLE_STRENGTH_POWER);
}

