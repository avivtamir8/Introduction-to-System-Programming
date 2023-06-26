cmake_minimum_required(VERSION 3.22)
project(ex4_new_f)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(ex4_mtm
        Mtmchkin.h Mtmchkin.cpp
        test.cpp
        #tool/main.cpp
        Exception.h
        utilities.h utilities.cpp
        Players/Player.cpp Players/Player.h
        Players/Fighter.cpp Players/Fighter.h
        Players/Wizard.cpp Players/Wizard.h
        Players/Rogue.cpp Players/Rogue.h
        Cards/Card.cpp Cards/Card.h
        Cards/Barfight.cpp Cards/Barfight.h
        Cards/Dragon.cpp Cards/Dragon.h
        Cards/Fairy.cpp Cards/Fairy.h
        Cards/Goblin.cpp Cards/Goblin.h
        Cards/Merchant.cpp Cards/Merchant.h
        Cards/Pitfall.cpp Cards/Pitfall.h
        Cards/Treasure.cpp Cards/Treasure.h
        Cards/Vampire.cpp Cards/Vampire.h
        Cards/Battle.cpp Cards/Battle.h
        Cards/BuffCards.cpp Cards/BuffCards.h
        Cards/Gang.cpp Cards/Gang.h
        )