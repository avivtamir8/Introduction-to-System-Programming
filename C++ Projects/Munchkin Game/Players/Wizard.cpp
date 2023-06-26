//
// Created by Amit on 08/06/2022.
//

#include "Wizard.h"

using std::string;

Wizard::Wizard(const string &name) :
        Player(name, "Wizard")
{}

void Wizard::heal(int hpToAdd)
{
    m_HP += (hpToAdd * DOUBLE_HP_GAIN);
    if (m_HP >= m_maxHP) {
        m_HP = m_maxHP;
    }
}

