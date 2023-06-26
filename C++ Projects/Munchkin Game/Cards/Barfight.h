//
// Created by Amit on 08/06/2022.
//

#ifndef EX4_MTM_BARFIGHT_H
#define EX4_MTM_BARFIGHT_H

#include "BuffCards.h"

class Barfight : public BuffCards {
private:
    static const int DAMAGE_TO_PLAYER = 10;

    /*
     * Applies a barfight card.
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

    //C'tor of Barfight
    Barfight();

    //Default d'tor
    ~Barfight() override = default;

};


#endif //EX4_MTM_BARFIGHT_H
