//
// Created by Amit on 08/06/2022.
//

#ifndef EX4_MTM_WIZARD_H
#define EX4_MTM_WIZARD_H

#include "Player.h"

class Wizard : public Player {
    static const int DOUBLE_HP_GAIN = 2;

public:

    /*
    * C'tor of Wizard class.
    * The c'tor is set to default as the Player's class c'tor.
    * @return
    *      A new wizard.
    */
    explicit Wizard(const std::string &name);

    /*
    * D'tor of Wizard class.
    * The d'tor is set to default as the Player's class d'tor.
    */
    ~Wizard() override = default;

    /*
     *  Copy c'tor of Wizard class
     * @param wizard - The wizard that we want to copy.
     * @return
     *      A new wizard based on an existing wizard.
    */
    Wizard(const Wizard &wizard) = default;

    /*
     * Operator overloading for =.
     *
     * @return
     *      An updated wizard with all the fields' values as the wizard of origin.
     */
    Wizard &operator=(const Wizard &wizard) = default;

    /*
    * Increase the wizard's health points by a given number.
    * For wizards, the heal is doubled the amount.
    * The wizard won't be healed if his health points are at the maximum defined for him.
    * @param hpToAdd - the number to increase the HP by.
    */
    void heal(int hpToAdd) override;
};


#endif //EX4_MTM_WIZARD_H
