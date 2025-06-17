#include <iostream>
#include <vector>
#include "prime.h"
#include "print.h"
#include "user_input.h"

#define ELEMENTS_PER_ROW 10


int main() {
    try {
        int num_primes = (int)getPositiveNumberFromUser("Enter number of primes: ");
        std::vector<int> primes_arr;
        fillPrimesArray(primes_arr, num_primes);
        printArray(primes_arr, ELEMENTS_PER_ROW);
        return 0;
    } catch (const std::exception& exception) {
        std::cout << "[!] " << exception.what() << '\n';
    }
}
