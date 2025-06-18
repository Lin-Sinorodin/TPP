#include <cmath>
#include "prime.h"

bool isEven(int num) {
    return num % 2 == 0;
}

bool isPrime(int num) {
    if (num < 0) {
        // p is prime if and only if -p is prime
        // https://math.stackexchange.com/a/1649531
        return isPrime(std::abs(num));
    }
    if (num <= 2) {
        return true;
    }
    if (isEven(num)) {
        return false;
    }

    // all even numbers (except 2) are not prime, so we skip them by iterating with i+=2
    for (int i = 3; i < std::sqrt(num); i+=2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int findNextPrime(int curr_num) {
    while (!isPrime(curr_num)) {
        curr_num++;
    }
    return curr_num;
}

void fillPrimesArray(std::vector<int>& primes_arr, unsigned int num_primes) {
    int curr_num = 1;
    for (int i = 0; i < num_primes; i++) {
        curr_num = findNextPrime(curr_num);
        primes_arr.push_back(curr_num);
        curr_num++;
    }
}