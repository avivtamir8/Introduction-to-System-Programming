//
// Created by Amit on 19/06/2022.
//

#ifndef EX4_MTM_GANG_H
#define EX4_MTM_GANG_H

#include "Battle.h"
#include <deque>

class Gang : public Card {

    static const int VAMPIRE_FORCE_STEAL = -1;
public:

    std::deque<std::unique_ptr<Battle>> m_gangCards;

    int m_numOfMonsters = 0;

    static bool checkSpecialCard(std::unique_ptr<Battle> &ptrToCard);

    /*
      * Handling the player's applyEncounter with a gang of monsters:
      *
      * @param player - The player.
      * @return
      *      void
     */
    void applyEncounter(std::unique_ptr<Player> &player) override;

    /*
    * Prints the card info:
    *
    * @return
    *      void
    */
    void printCard(std::ostream &os) const override;

    /*
     * C'tor does not have parameters - name will be set at the battle card's C'tor.
     * Default D'tor.
     */
    Gang();

    ~Gang() override = default;

    Gang(const Gang &gangToCopy);

    Gang & operator=(const Gang &gangToCopy);

};


#endif //EX4_MTM_GANG_H
