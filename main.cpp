#include <iostream>
#include <list>
#include "prime.h"


int main() {
    std::list<int> nums = {2, 7, 31, 50, 93, 113};
    for (auto num: nums) {
        bool num_is_prime = isPrime(num);
        std::cout << "isPrime(" << num << ") = " << (num_is_prime ? "True" : "False") << std::endl;
    }
    return 0;
}
