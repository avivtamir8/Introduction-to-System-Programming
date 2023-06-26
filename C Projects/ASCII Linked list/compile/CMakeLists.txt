cmake_minimum_required(VERSION 3.22)
project(compile C)

set(CMAKE_C_STANDARD 99)

add_executable(compile RLEList_example_test.c
        RLEList.c)
