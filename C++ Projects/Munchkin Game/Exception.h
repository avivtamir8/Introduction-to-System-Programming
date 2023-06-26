//
// Created by Amit on 09/06/2022.
//

#ifndef EX4_MTM_EXCEPTION_H
#define EX4_MTM_EXCEPTION_H

#include <iostream>
#include "utilities.h"

/* ---------------------------------------------------------------------------------------------- */
// Exceptions considering specific requirements from the exercise

class DeckFileNotFound : public std::exception {
    const char *what() const noexcept override
    {
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError : public std::exception {
private:
    std::string m_message;
public:
    explicit DeckFileFormatError(int lineNumber) :
            m_message("Deck File Error: File format error in line " + std::to_string(lineNumber))
    {};

    const char *what() const noexcept override
    {
        return m_message.data();
    }
};

class DeckFileInvalidSize : public std::exception {

    const char *what() const noexcept override
    {
        return "Deck File Error: Deck size is invalid";
    }
};

class InvalidTeamSize : public std::exception {};

/* ---------------------------------------------------------------------------------------------- */
// Exceptions considering player-related classes.

class InsufficientFunds : public std::exception {};


#endif //EX4_MTM_EXCEPTION_H
