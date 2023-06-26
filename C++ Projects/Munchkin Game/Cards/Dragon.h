//
// Created by Amit on 08/06/2022.
//

#ifndef EX4_MTM_DRAGON_H
#define EX4_MTM_DRAGON_H

#include "Battle.h"

class Dragon : public Battle {
private:

    static const int DRAGON_LOOT = 1000;
    static const int DRAGON_FORCE = 25;
    static const int DRAGON_DAMAGE = -1; //when the player get damaged - if the amount is -1 - kill the player

    /*
     * Handling the player's applyEncounter with the dragon:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(std::unique_ptr<Player> &player) override;

    /*
     * Prints the dragon's info:
     *
     * @return
     *      void
    */
    void printCard(std::ostream &os) const override;

public:

    /*
    * C'tor does not have parameters - name will be set at the battle card's C'tor.
    * Default D'tor.
    */
    Dragon();

    ~Dragon() override = default;

    Dragon(const Dragon &dragon) = default;

    //clone function for Dragon
    std::unique_ptr<Battle> clone() const override;


};


#endif //EX4_MTM_DRAGON_H
