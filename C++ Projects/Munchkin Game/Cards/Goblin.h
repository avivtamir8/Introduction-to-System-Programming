//
// Created by Amit on 08/06/2022.
//

#ifndef EX4_MTM_GOBLIN_H
#define EX4_MTM_GOBLIN_H

#include "Battle.h"

class Goblin : public Battle {
private:

    static const int GOBLIN_LOOT = 2;
    static const int GOBLIN_FORCE = 6;
    static const int GOBLIN_DAMAGE = 10; //when the player get damaged

    /*
     * Handling the player's applyEncounter with the goblin:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(std::unique_ptr<Player> &player) override;

    /*
     * Prints the goblin's info:
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
    Goblin();

    ~Goblin() override = default;

    Goblin(const Goblin &goblin) = default;

    //clone function for Goblin
     std::unique_ptr<Battle> clone() const override;

};


#endif //EX4_MTM_GOBLIN_H
