//
// Created by Amit on 08/06/2022.
//

#include "Pitfall.h"
#include "../Players/Rogue.h"


Pitfall::Pitfall() :
        BuffCards("Pitfall")
{}

bool Pitfall::checkSpecialPlayer(std::unique_ptr<Player> &ptrToPlayer) const
{
    try {
        dynamic_cast<Rogue &>(*ptrToPlayer);
    }
    catch (const std::bad_cast &e) {
        return false;
    }
    return true;
}

void Pitfall::applyEncounter(std::unique_ptr<Player> &player)
{
    bool isRogue = checkSpecialPlayer(player);
    if (!isRogue) {
        player->damage(DAMAGE_TO_PLAYER);
    }
    printPitfallMessage(isRogue);
}
