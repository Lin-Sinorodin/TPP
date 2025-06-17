#include <iostream>
#include <cmath>

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

int main() {
    unsigned int nums[] = {2, 7, 31, 50, 93, 113};
    for (auto num: nums) {
        bool num_is_prime = isPrime(num);
        std::cout << "isPrime(" << num << ") = " << (num_is_prime ? "True" : "False") << std::endl;
    }
    return 0;
}
