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

    for (int i = 3; i < std::sqrt(num); i+=2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
