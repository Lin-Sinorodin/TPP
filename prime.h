#ifndef TPP_PRIME_H
#define TPP_PRIME_H

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

#endif //TPP_PRIME_H
