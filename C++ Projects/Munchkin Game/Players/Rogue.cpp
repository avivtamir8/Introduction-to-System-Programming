//
// Created by Amit on 08/06/2022.
//

#include "Rogue.h"

void Rogue::addCoins(int coinsToAdd)
{
    m_coins += (coinsToAdd * DOUBLE_COINS_GAIN);
}

Rogue::Rogue(const std::string &name) :
        Player(name, "Rogue")
{}
