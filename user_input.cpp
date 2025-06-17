#include <iostream>
#include <string>
#include "user_input.h"

long getNumberFromUser(const std::string& msg) {
    std::string num_str;
    std::cout << msg;
    std::cin >> num_str;
    return std::stol(num_str);
}

long getPositiveNumberFromUser(const std::string& msg) {
    long num = getNumberFromUser(msg);
    if (num < 0) {
        throw std::invalid_argument("getPositiveNumberFromUser: negative value");
    }
    return num;
}
