cmake_minimum_required(VERSION 3.28)
project(TPP)

set(CMAKE_CXX_STANDARD 17)

add_executable(TPP main.cpp
        prime.cpp
        prime.h
        user_input.cpp
        user_input.h
        cli.cpp
        cli.h)
