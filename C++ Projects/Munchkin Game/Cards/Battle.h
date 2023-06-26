//
// Created by Amit on 08/06/2022.
//

#ifndef EX4_MTM_BATTLE_H
#define EX4_MTM_BATTLE_H

#include "Card.h"

class Battle : public Card {

protected:

    int m_loot;
    int m_monsterForce;
    int m_damageToPlayer;

    /*
     * Checks if the player won a battle.
     * The outcome varies depending on the player's stats, class and the monster he is fighting.
     *
     * @param player - The player.
     * @return
     *      void
    */
    bool checkWin(const Player &player) const;

    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    virtual void printCard(std::ostream &os) const override = 0;

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(std::unique_ptr<Player> &player) override = 0;

public:

    /*
     * C'tor of Battle class
     *
     * @param name - classifies the card, specifically the monster type.
     * @param loot - The amount of gold won if the battle is won.
     * @param monsterForce - the amount of force points the monster has.
     * @param damageToPlayer - the amount of damage that will be inflicted if the player loses.
     * @return
     *      A new instance of Card.
    */
    Battle(const std::string& name, int loot, int monsterForce, int damageToPlayer);

    /*
     * Default D'tor.
     */
    ~Battle() override = default;

    /*
     * Getter for specific fields.
     */
    int getMonsterForce() const;

    int getMonsterDamage() const;

    int getMonsterLoot() const;

    std::string getMonsterName() const;

    //clone function for battle cards
    virtual std::unique_ptr<Battle> clone() const = 0;
};


#endif //EX4_MTM_BATTLE_H
