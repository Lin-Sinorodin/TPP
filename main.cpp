#include <iostream>
#include <vector>
#include "prime.h"
#include "cli.h"
#include "user_input.h"

#define ELEMENTS_PER_ROW 10


int main() {
    try {
        unsigned int num_primes = static_cast<unsigned int>(getPositiveNumberFromUser("Enter number of primes: "));
        std::vector<int> primes_arr;
        fillPrimesArray(primes_arr, num_primes);
        printArray(primes_arr, ELEMENTS_PER_ROW);
        return 0;
    } catch (const std::exception& exception) {
        std::cout << "[!] " << exception.what() << std::endl;
    }
}
