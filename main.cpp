#include <iostream>
#include <cmath>
#include <string>

/**
 * Get a number from the user, raises if not a valid number.
 *
 * @param msg Message to print when asking for the number.
 * @return The number typed by the user, as long.
 */
long getNumberFromUser(const std::string& msg) {
    std::string num_str;
    std::cout << msg;
    std::cin >> num_str;
    return std::stol(num_str);
}

/**
 * Get a number from the user, raises if not a valid positive number.
 *
 * @param msg Message to print when asking for the number.
 * @return The number typed by the user, as long.
 */
long getPositiveNumberFromUser(const std::string& msg) {
    long num = getNumberFromUser(msg);
    if (num < 0) {
        throw std::invalid_argument("getPositiveNumberFromUser: negative value");
    }
    return num;
}

void squareRootCLI() {
    try {
        long num = getPositiveNumberFromUser("Calculate square root of: ");
        std::cout << "Square root: " << std::sqrt(num) << '\n';
    } catch (std::invalid_argument const& ex) {
        std::cout << "[!] " << ex.what() << '\n';
    } catch (std::out_of_range const& ex) {
        std::cout << "[!] " << ex.what() << '\n';
    }
}

int main() {
    squareRootCLI();
    return 0;
}
