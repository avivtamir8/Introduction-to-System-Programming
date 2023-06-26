//
// Created by Amit on 08/06/2022.
//

#include "Player.h"
#include "../utilities.h"

using std::string;

Player::Player(const string &name, const string &job) :
        m_name(name),
        m_level(STARTING_LEVEL),
        m_force(DEFAULT_FORCE),
        m_maxHP(DEFAULT_MAX_HP),
        m_HP(m_maxHP),
        m_coins(STARTING_COINS),
        m_job(job)
{}

void Player::levelUp()
{
    if (m_level == MAX_LEVEL) {
        return;
    }
    m_level++;
}

void Player::buff(int forceToAdd)
{
    m_force += forceToAdd;
    if (m_force < NO_FORCE) {
        m_force = NO_FORCE;
    }
}

void Player::heal(int hpToAdd)
{
    m_HP += hpToAdd;
    if (m_HP >= m_maxHP) {
        m_HP = m_maxHP;
    }
}

void Player::damage(int damageToPlayer)
{
    if (damageToPlayer == DRAGON_DAMAGE) {
        m_HP = OUT_OF_HP;
        return;
    }
    m_HP -= damageToPlayer;
    if (m_HP < OUT_OF_HP) {
        m_HP = OUT_OF_HP;
    }
}

bool Player::isKnockedOut() const
{
    return m_HP == OUT_OF_HP;
}

void Player::addCoins(int coinsToAdd)
{
    m_coins += coinsToAdd;
}

bool Player::pay(int amountToPay)
{
    if (m_coins < amountToPay) {
        throw InsufficientFunds();
    }
    if (m_coins >= amountToPay) {
        m_coins -= amountToPay;
        return true;
    }
    return false;
}

int Player::getAttackStrength() const
{
    return m_level + m_force;
}

std::string Player::getName() const
{
    return m_name;
}

int Player::getCoins() const
{
    return m_coins;
}

bool Player::haveWon() const
{
    if (m_level == MAX_LEVEL) {
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Player &player)
{
    std::ostream &osr = os;
    printPlayerDetails(osr, player.m_name, player.m_job, player.m_level, player.m_force, player.m_HP,
                       player.m_coins);
    return osr;
}


