#include <iostream>
#include "hash_table.h"

int main() {
    HashTable countryToCapital{100};
    countryToCapital.add("Israel", "Jerusalem");
    HashTable countryToCapital1{countryToCapital};
    std::cout << countryToCapital1.numElements() << std::endl;

    std::cout << countryToCapital.size() << std::endl;
    std::cout << countryToCapital.numElements() << std::endl;
    std::cout << countryToCapital.getByKey("Israel") << std::endl;
    std::cout << countryToCapital.keyExists("Israel") << std::endl;
    std::cout << countryToCapital.valueExists("Jerusalem") << std::endl;
    countryToCapital.deleteByKey("Israel");
    std::cout << countryToCapital.numElements() << std::endl;

    return 0;
}
