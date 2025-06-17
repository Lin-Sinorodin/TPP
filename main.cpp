#include <iostream>
#include <cmath>
#include <string>

float getNumberFromUser(const std::string& msg) {
    char buff[sizeof(int) * 8];
    std::cout << msg;
    std::cin >> buff;
    return strtof(buff, nullptr);
}

int squareRootCLI() {
    float num = getNumberFromUser("Calculate square root of: ");
    if (num <= 0) {
        throw std::runtime_error("Invalid input!");
    }

    std::cout << "Square root: " << std::sqrt(num) << std::endl;
    return 0;

}

int main() {
    return squareRootCLI();
}
