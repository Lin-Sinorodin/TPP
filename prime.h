#ifndef TPP_PRIME_H
#define TPP_PRIME_H

#include <vector>

/**
 * Check if the given number is even.
 *
 * @param num An int to check if it's even.
 * @return If even return true, else return false.
 */
bool isEven(int num);

/**
 * Check if the given number is prime using "Trial division".
 *
 * One can read more about it here: https://en.wikipedia.org/wiki/Trial_division.
 * For negative numbers the abs is applied on the input (see code for details).
 *
 * @param num An int to check if it's prime.
 * @return If prime return true, else return false.
 */
bool isPrime(int num);

/**
 * Increment curr_num until it's a prime number, when found return it and exit the function.
 *
 * @param curr_num A reference to an integer number, to check if it's prime and increment if not.
 * @return The found prime number.
 */
int findNextPrime(int& curr_num);

/**
 * Fill the given array with primes.
 *
 * @param primes_arr A pointer to an array of ints, to fill with primes.
 * @param num_primes Number of primes to fill in the array.
 */
void fillPrimesArray(std::vector<int>& primes_arr, int num_primes);

#endif //TPP_PRIME_H
