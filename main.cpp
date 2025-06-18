#include <iostream>
#include "string2.h"


int main() {
    String str1{ "Hello "};
    String str2{ "World"};
    str1.print();

    str1 += str2;
    str1.print();

    str1.insert(5, ",");
    str1.print();

    std::cout << "str1.find(str2): " << str1.find(str2) << std::endl;
    std::cout << "str1.find(\",\"): " << str1.find(",") << std::endl;
    std::cout << "str1.find(\"l\"): " << str1.find("l") << std::endl;
    std::cout << "str1.find(\"l\", 3): " << str1.find("l", 3) << std::endl;
    return 0;
}
