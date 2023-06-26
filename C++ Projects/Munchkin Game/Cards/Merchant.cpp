//
// Created by Amit on 08/06/2022.
//

#include "Merchant.h"
#include <sstream>

using std::string;

void Merchant::applyEncounter(std::unique_ptr<Player> &player)
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player->getName(), player->getCoins());
    string merchantChoiceString;
    int choice = tryToGetInput();
    int cost = 0;
    try {
        switch (choice) {
            case BUY_HP:
                cost = HP_COST;
                player->pay(cost);
                player->heal(ADD_HP);
                break;
            case BUY_STRENGTH:
                cost = STRENGTH_COST;
                player->pay(cost);
                player->buff(ADD_FORCE);
                break;
        }
    }
    catch (InsufficientFunds &e) {
        printMerchantInsufficientCoins(std::cout);
        cost = DO_NOTHING;
    }
    printMerchantSummary(std::cout, player->getName(), choice, cost);
}

Merchant::Merchant() :
        Card("Merchant")
{}

int Merchant::tryToGetInput()
{
    int choice = PLACEHOLDER;
    string merchantChoiceString;
    bool validInput = false;
    while (!validInput) {
        try {
            getline(std::cin, merchantChoiceString);
            if (merchantChoiceString.size() > INPUT_SIZE) {
                printInvalidInput();
                continue;
            }
            choice = std::stoi(merchantChoiceString);
            if (choice == DO_NOTHING || choice == BUY_HP || choice == BUY_STRENGTH) {
                validInput = true;
            } else printInvalidInput();
        }
        catch (std::invalid_argument &e) {
            printInvalidInput();
        }
    }
    return choice;
}

void Merchant::printCard(std::ostream &os) const
{
}
