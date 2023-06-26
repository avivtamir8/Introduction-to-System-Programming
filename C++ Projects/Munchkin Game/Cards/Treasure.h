//
// Created by Amit on 08/06/2022.
//

#ifndef EX4_MTM_TREASURE_H
#define EX4_MTM_TREASURE_H

#include "BuffCards.h"

class Treasure : public BuffCards {
private:
    static const int TREASURE_COINS = 10;

    /*
     * Applies a treasure card.
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

    //C'tor of Treasure
    Treasure();

    //Default D'tor
    ~Treasure() override = default;
};


#endif //EX4_MTM_TREASURE_H
