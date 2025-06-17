#include <iostream>
#include <memory>
#include <iomanip>
#include "prime.h"
#include "user_input.h"

#define COLS 10

/**
 * Fill the given array with primes.
 *
 * @param primes_arr A pointer to an array of ints, to fill with primes.
 * @param num_primes Number of primes to fill in the array.
 */
void fillPrimesArray(const std::shared_ptr<int[]>& primes_arr, int num_primes) {
    int last_num = 1;
    for (int i = 0; i < num_primes; i++) {
        while (!isPrime(last_num)) {
            last_num++;
        }
        primes_arr[i] = last_num;
        last_num++;
    }
}

/**
 * Print the given array of primes.
 *
 * @param primes_arr A pointer to an array of primes.
 * @param num_primes Number of primes in the array.
 * @param cols The number of numbers per row in the printed output.
 */
void printPrimesArray(const std::shared_ptr<int[]>& primes_arr, int num_primes, int cols) {
    for (int i = 0; i < num_primes; i++) {
        std::cout << std::setw(4) << std::left << primes_arr[i] << ' ';
        if (i % cols == (cols - 1)) {
            std::cout << '\n';
        }
    }
    std::cout << '\n';
}


int main() {
    int num_primes = (int)getPositiveNumberFromUser("Enter number of primes: ");
    std::shared_ptr<int[]> primes_arr = std::make_shared<int>(num_primes);
    fillPrimesArray(primes_arr, num_primes);
    printPrimesArray(primes_arr, num_primes, COLS);
    return 0;
}
