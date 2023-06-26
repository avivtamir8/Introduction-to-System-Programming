//
// Created by Amit on 08/06/2022.
//

#include "Treasure.h"

void Treasure::applyEncounter(std::unique_ptr<Player> &player)
{
    player->addCoins(TREASURE_COINS);
    printTreasureMessage();
}

Treasure::Treasure() :
        BuffCards("Treasure")
{}

bool Treasure::checkSpecialPlayer(std::unique_ptr<Player> &ptrToPlayer) const
{
    return false;
}
