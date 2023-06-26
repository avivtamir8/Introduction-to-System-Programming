//
// Created by Amit on 08/06/2022.
//

#ifndef EX4_MTM_FIGHTER_H
#define EX4_MTM_FIGHTER_H

#include "Player.h"

class Fighter : public Player {

    static const int DOUBLE_STRENGTH_POWER = 2;

public:

    /*
    * C'tor of Fighter class.
    * The c'tor is set to default as the Player's class c'tor.
    * @return
    *      A new wizard.
    */
    explicit Fighter(const std::string &name);

    /*
     *  Copy c'tor of Rogue class
     * @param fighter - The fighter that we want to copy.
     * @return
     *      A new fighter based on an existing fighter.
    */
    Fighter(const Fighter &fighter) = default;

    /*
     * Operator overloading for =.
     *
     * @return
     *      An updated fighter with all the fields' values as the fighter of origin.
     */
    Fighter &operator=(const Fighter &fighter) = default;

    /*
    * D'tor of Fighter class.
    * The d'tor is set to default as the Player's class d'tor.
    */
    ~Fighter() override = default;

    /*
    * calculates the attack strength based on the fighter's level and force points.
    *
    * @return
    *      the calculated value for attack strength, calculated differently for fighter..
    */
    int getAttackStrength() const override;

};


#endif //EX4_MTM_FIGHTER_H
