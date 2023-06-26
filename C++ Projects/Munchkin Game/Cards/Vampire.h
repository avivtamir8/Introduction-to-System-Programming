//
// Created by Amit on 08/06/2022.
//

#ifndef EX4_MTM_VAMPIRE_H
#define EX4_MTM_VAMPIRE_H

#include "Battle.h"

class Vampire : public Battle {
private:
    static const int VAMPIRE_LOOT = 2;
    static const int VAMPIRE_FORCE = 10;
    static const int VAMPIRE_DAMAGE = 10;
    static const int VAMPIRE_FORCE_STEAL = -1;

    /*
     * Handling the player's applyEncounter with the vampire:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(std::unique_ptr<Player> &player) override;

    /*
     * Prints the vampire's info:
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
    Vampire();

    ~Vampire() override = default;

    Vampire(const Vampire &vampire) = default;

    //clone function for Vampire
    std::unique_ptr<Battle> clone() const override;


};


#endif //EX4_MTM_VAMPIRE_H
