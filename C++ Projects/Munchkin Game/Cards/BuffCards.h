//
// Created by Amit on 09/06/2022.
//

#ifndef EX4_MTM_BUFFCARDS_H
#define EX4_MTM_BUFFCARDS_H

#include "Card.h"

class BuffCards : public Card {

protected:

    /*
     * Handling the player's applyEncounter with the buff card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(std::unique_ptr<Player> &player) override = 0;

    /*
     * This function helps us take different action for specific types of players.
     *
     * @param ptrToPlayer
     * @return
     *      bool
     */
    virtual bool checkSpecialPlayer(std::unique_ptr<Player> &ptrToPlayer) const = 0;

    /*
   * Prints the card info (for non battle cards does nothing)
   *
   * @return
   *      void
   */
    virtual void printCard(std::ostream &os) const override;

public:

    /*
     * C'tor of BuffCards class
     *
     * @param name - classifies the buff card.
     * @return
     *      A new instance of buff card.
    */
    explicit BuffCards(const std::string &name);

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~BuffCards() override = default;
};


#endif //EX4_MTM_BUFFCARDS_H
