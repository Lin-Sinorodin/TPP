cmake_minimum_required(VERSION 3.28)
project(TPP)

set(CMAKE_CXX_STANDARD 17)

add_executable(TPP main.cpp
        hash_table.cpp
        hash_table.h
        linked_list.cpp
        linked_list.h)
