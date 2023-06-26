//
// Created by Amit on 08/06/2022.
//

#ifndef EX4_MTM_ROGUE_H
#define EX4_MTM_ROGUE_H

#include "Player.h"


class Rogue : public Player {

    static const int DOUBLE_COINS_GAIN = 2;

public:

    /*
    * C'tor of Rogue class.
    * The c'tor is set to default as the Player's class c'tor.
    * @return
    *      A new rogue.
    */
    explicit Rogue(const std::string &name);

    /*
     *  Copy c'tor of Rogue class
     * @param rogue - The rogue that we want to copy.
     * @return
     *      A new rogue based on an existing rogue.
    */
    Rogue(const Rogue &rogue) = default;

    /*
     * Operator overloading for =.
     *
     * @return
     *      An updated rogue with all the fields' values as the rogue of origin.
     */
    Rogue &operator=(const Rogue &rogue) = default;

    /*
    * D'tor of Rogue class.
    * The d'tor is set to default as the Player's class d'tor.
    */
    ~Rogue() override = default;

    /*
     * Add coins to the rogue.
     * @param coinsToAdd - the number to increase the coins by. will be doubled for the rogue class.
     */
    void addCoins(int coinsToAdd) override;
};


#endif //EX4_MTM_ROGUE_H
