//
// Created by Amit on 08/06/2022.
//

#ifndef EX4_MTM_CARD_H
#define EX4_MTM_CARD_H

#include "../Players/Player.h"
#include "../utilities.h"
#include <memory>

/*
 *  CardType:
 *  Each card has an type:
 *  BATTLE - Battle against a monster.
 *  BUFF - Increase your player's force by 'm_force' points of CardStats.
 *  HEAL - Increase your player's HP by 'm_heal' points  of CardStats (no more than maxHP points).
 *  TREASURE - Get 'm_profit' coins of CardStats.
*/// The type of the Card

class Card {

    /*
    * Prints the card info:
    *
    * @return
    *      void
    */
    friend std::ostream &operator<<(std::ostream &os, const Card &card);

protected:

    std::string m_name;

public:

    /*
     * C'tor of Card class
     *
     * @param name - classifies the card.
     * @return
     *      A new instance of Card.
    */
    explicit Card(const std::string &name);


    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(std::unique_ptr<Player> &player) = 0;

    //returns the name of the card
    std::string getName() const;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card &) = default;

    Card &operator=(const Card &other) = default;

    virtual ~Card() = default;

    //print function for cards
    virtual void printCard(std::ostream &os) const = 0;

};


#endif //EX4_MTM_CARD_H
