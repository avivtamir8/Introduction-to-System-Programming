//
// Created by Amit on 08/06/2022.
//

#include "Fairy.h"
#include "../Players/Wizard.h"


Fairy::Fairy() :
        BuffCards("Fairy")
{}

bool Fairy::checkSpecialPlayer(std::unique_ptr<Player> &ptrToPlayer) const
{

    try {
        dynamic_cast<Wizard &>(*ptrToPlayer);
    }
    catch (const std::bad_cast &e) {
        return false;
    }
    return true;
}

void Fairy::applyEncounter(std::unique_ptr<Player> &player)
{
    bool isWizard = checkSpecialPlayer(player);
    if (isWizard) {
        player->heal(AMOUNT_TO_HEAL);
    }
    printFairyMessage(isWizard);
}
