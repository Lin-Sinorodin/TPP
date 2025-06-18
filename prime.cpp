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

int findNextPrime(int currNum) {
    while (!isPrime(currNum)) {
        currNum++;
    }
    return currNum;
}

void fillPrimesArray(std::vector<int>& primesArr, unsigned int numPrimes) {
    int curr_num = 1;
    for (int i = 0; i < numPrimes; i++) {
        curr_num = findNextPrime(curr_num);
        primesArr.push_back(curr_num);
        curr_num++;
    }
}