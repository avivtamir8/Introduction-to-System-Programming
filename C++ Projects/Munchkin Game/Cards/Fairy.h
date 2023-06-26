//
// Created by Amit on 08/06/2022.
//

#ifndef EX4_MTM_FAIRY_H
#define EX4_MTM_FAIRY_H

#include "BuffCards.h"

class Fairy : public BuffCards {
private:
    static const int AMOUNT_TO_HEAL = 10;

    /*
     * Applies a Fairy card.
     * The outcome can change depending on the player's class.
     */
    void applyEncounter(std::unique_ptr<Player> &player) override;

    /*
     * This function helps us take different action for specific types of players.
     *
     * @param ptrToPlayer
     * @return
     *      bool
     */
    bool checkSpecialPlayer(std::unique_ptr<Player> &ptrToPlayer) const override;

public:

    //Ctor of Fairy
    Fairy();

    //Default D'tor
    ~Fairy() override = default;

};


#endif //EX4_MTM_FAIRY_H
