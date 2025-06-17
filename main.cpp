#include <iostream>
#include <cmath>
#include <memory>

float getNumberFromUser(std::string_view msg) {
    char buff[sizeof(int) * 8];
    std::cout << msg;
    std::cin >> buff;
    return strtof(buff, nullptr);
}

bool isPrime(unsigned int num) {
    if (num % 2 == 0) {
        return false;
    }

    for (int i = 3; i < std::sqrt(num); i+=2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}


void fillPrimesArray(std::shared_ptr<int[]> primes_arr, int num_primes) {

}

int main() {
    int num_primes = (int)getNumberFromUser("Enter number of primes: ");
    if (num_primes <= 0) {
        std::cout << "Invalid number of primes, Exiting..." << std::endl;
        return 1;
    }

    std::shared_ptr<int[]> primes_arr = std::make_shared<int>(num_primes);

    return 0;
}
