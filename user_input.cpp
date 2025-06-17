#include <iostream>
#include <string>
#include "user_input.h"

long getNumberFromUser(const std::string& msg) {
    std::string numStr;
    std::cout << msg;
    std::cin >> numStr;

    try {
        return std::stol(numStr);
    } catch (std::invalid_argument const& ex) {
        throw std::invalid_argument("getNumberFromUser: not a number");
    } catch (std::out_of_range const& ex) {
        throw std::out_of_range("getNumberFromUser: out of bounds");
    }
}

unsigned long getPositiveNumberFromUser(const std::string& msg) {
    long num = getNumberFromUser(msg);
    if (num < 0) {
        throw std::invalid_argument("getPositiveNumberFromUser: negative value");
    }
    return num;
}
