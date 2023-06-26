//
// Created by Amit on 08/06/2022.
//

#include "Card.h"

Card::Card(const std::string &name) :
        m_name(name)
{}

std::ostream &operator<<(std::ostream &os, const Card &card)
{
    std::ostream &osr = os;
    printCardDetails(osr, card.m_name);
    card.printCard(osr);
    printEndOfCardDetails(osr);
    return osr;
}

std::string Card::getName() const
{
    return m_name;
}
