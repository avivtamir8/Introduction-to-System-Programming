//
// Created by Amit on 08/06/2022.
//

#include "Barfight.h"
#include "../Players/Fighter.h"

void Barfight::applyEncounter(std::unique_ptr<Player> &player)
{
    bool isFighter = checkSpecialPlayer(player);
    if (!isFighter) {
        player->damage(DAMAGE_TO_PLAYER);
    }
    printBarfightMessage(isFighter);
}

Barfight::Barfight() :
        BuffCards("Barfight")
{}


bool Barfight::checkSpecialPlayer(std::unique_ptr<Player> &ptrToPlayer) const
{
    try {
        dynamic_cast<Fighter &>(*ptrToPlayer);
    }
    catch (const std::bad_cast &e) {
        return false;
    }
    return true;
}
