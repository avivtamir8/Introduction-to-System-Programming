//
// Created by Amit on 08/06/2022.
//

#ifndef EX4_MTM_MERCHANT_H
#define EX4_MTM_MERCHANT_H

#include "Card.h"


class Merchant : public Card {

    static const int DO_NOTHING = 0;
    static const int BUY_HP = 1;
    static const int BUY_STRENGTH = 2;
    static const int HP_COST = 5;
    static const int STRENGTH_COST = 10;
    static const int ADD_FORCE = 1;
    static const int ADD_HP = 1;
    static const int INPUT_SIZE = 1;
    static const int PLACEHOLDER = -1;

    /*
     * Handling the player's applyEncounter with the Merchant card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(std::unique_ptr<Player> &player) override;

    /*
     * This function gets input from the player to make a choice for Merchant.
     * Exceptions and second tries will be accounted for.
     */
    static int tryToGetInput();

    /*
    * Prints the card info (for non battle cards does nothing)
    *
    * @return
    *      void
    */
    void printCard(std::ostream &os) const override;

public:

    //C'tor of Merchant
    Merchant();

    //Default D'tor
    ~Merchant() override = default;

};


#endif //EX4_MTM_MERCHANT_H
