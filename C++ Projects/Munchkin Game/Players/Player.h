//
// Created by Amit on 08/06/2022.
//

#ifndef EX4_MTM_PLAYER_H
#define EX4_MTM_PLAYER_H

#include <iostream>
#include <memory>

class Player {
protected:

    static const int STARTING_LEVEL = 1;
    static const int STARTING_COINS = 10;
    static const int DEFAULT_FORCE = 5;
    static const int DEFAULT_MAX_HP = 100;
    static const int NO_FORCE = 0;
    static const int MAX_LEVEL = 10;
    static const int OUT_OF_HP = 0;
    static const int DRAGON_DAMAGE = -1;

    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;
    std::string m_job;

public:

    /*
    * C'tor of Player class
    *
    * @param name - The name of the player.
    * @param maxHP - The maximum health points of the player (default value shall be set to 100).
    * @param force - The force points of the player (default value shall be set to 5).
    * @return
    *      A new player.
    */
    explicit Player(const std::string &name, const std::string &job);

    /*
     *  Copy c'tor of Player class
     * @param player - The player that we want to copy.
     * @return
     *      A new player based on an existing player.
    */
    Player(const Player &player) = default;

    /*
     * Operator overloading for =.
     *
     * @return
     *      An updated player with all the fields' values as the player of origin.
     */
    Player &operator=(const Player &player) = default;

    /*
     * d'tor of Player class
     */
    virtual ~Player() = default;

    /*
     * Increase the player's level by 1.
     * if the player's level is 10 then nothing will be done.
    */
    void levelUp();

    /*
     * Returns the player's current coins.
     *
     * @return
     *      the current coins of the player
    */
    int getCoins() const;

    //get the players name
    std::string getName() const;

    /*
     * Increase the player's force points by a given number.
     * If the number is negative, do nothing.
     * @param forceToAdd - the number to increase the force by.
     * @return
     *      the updated force points of the player
     */
    void buff(int forceToAdd);

    /*
     * Increase the player's health points by a given number.
     * If the number is negative, do nothing.
     * The player won't be healed if his health points are at the maximum defined for him.
     * @param hpToAdd - the number to increase the HP by
     */
    virtual void heal(int hpToAdd);

    /*
     * decrease the player's health points by a given number.
     * If the number is negative, do nothing.
     * if the given number reduces the health points below zero, the hp will be set to zero.
     * @param damageToPlayer - the number to damage the player.
     */
    void damage(int damageToPlayer);

    /*
     * Checks if the player is knocked out.
     *
     * @return
     *     true if the player's hp is zero, otherwise false.
     */
    bool isKnockedOut() const;

    /*
     * Add coins to the player.
     * If the number is negative, do nothing.
     * @param coinsToAdd - the number to increase the coins by
     */
    virtual void addCoins(int coinsToAdd);

    /*
     * Reduce coins from the player, if he can afford it.
     * If the amount to pay is 0 or negative, do nothing.
     * @param amountToPay - the number the player needs to pay.
     * @return
     *     true if the payment went through correctly, otherwise false.
     */
    bool pay(int amountToPay);

    /*
     * calculates the attack strength based on the player's level and force points.
     *
     * @return
     *      the calculated value for attack strength.
     */
    virtual int getAttackStrength() const;

    /*
     * checks if the player reached level 10 - meaning he won
     *
     * @return
     *      true if the player won
     *      false otherwise
     */
    bool haveWon() const;

    //print operator for player
    friend std::ostream &operator<<(std::ostream &os, const Player &player);
};


#endif //EX4_MTM_PLAYER_H
