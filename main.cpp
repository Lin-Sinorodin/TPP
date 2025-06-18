#include <iostream>
#include <vector>
#include "prime.h"
#include "cli.h"
#include "user_input.h"

#define ELEMENTS_PER_ROW 10


int main() {
    try {
        unsigned int numPrimes = static_cast<unsigned int>(getPositiveNumberFromUser("Enter number of primes: "));
        std::vector<int> primesArr;
        fillPrimesArray(primesArr, numPrimes);
        printArray(primesArr, ELEMENTS_PER_ROW);
        return 0;
    } catch (const std::exception& exception) {
        std::cout << "[!] " << exception.what() << std::endl;
    }
}
