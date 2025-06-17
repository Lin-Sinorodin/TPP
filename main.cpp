#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

float getNumberFromUser(std::string_view msg) {
    char buff[sizeof(int) * 8];
    std::cout << msg;
    std::scanf("%s", buff);
    return strtof(buff, nullptr);
}

int squareRootCLI() {
    float num = getNumberFromUser("Calculate square root of: ");
    if (num > 0) {
        std::cout << "Square root: " << std::sqrt(num) << std::endl;
        return 0;
    } else {
        std::cout << "Invalid input!\n";
        return 1;
    }
}

int main() {
    return squareRootCLI();
}
