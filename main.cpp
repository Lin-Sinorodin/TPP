#include <iostream>
#include "hash_table.h"

int main() {
    HashTable countryToCapital{3};
    std::cout << "Country to Capital Hash Table" << std::endl;
    std::cout << "initial size():         " << countryToCapital.size() << std::endl << std::endl;

    countryToCapital.add("Argentina", "Buenos Aires");
    countryToCapital.add("China", "Beijing");
    countryToCapital.add("France", "Paris");
    countryToCapital.add("Germany", "Berlin");
    countryToCapital.add("Hungary", "Budapest");
    countryToCapital.add("India", "New Delhi");
    countryToCapital.add("Israel", "Jerusalem");
    countryToCapital.add("Italy", "Rome");
    countryToCapital.add("Japan", "Tokyo");
    countryToCapital.add("Thailand", "Bangkok");
    countryToCapital.add("UK", "London");

    std::cout << "size():                 " << countryToCapital.size() << std::endl;
    std::cout << "numElements():          " << countryToCapital.numElements() << std::endl;
    std::cout << "keyExists(Israel):      " << countryToCapital.keyExists("Israel") << std::endl;
    std::cout << "valueExists(Jerusalem): " << "" << countryToCapital.valueExists("Jerusalem") << std::endl;
    std::cout << "getByKey(Israel):       " << countryToCapital.getByKey("Israel") << std::endl;

    std::cout << std::endl << "deleteByKey(Israel)" << std::endl;
    countryToCapital.deleteByKey("Israel");
    std::cout << "numElements():          " << countryToCapital.numElements() << std::endl;

    return 0;
}
