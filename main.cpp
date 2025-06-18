#include <iostream>
#include "string2.h"


int main() {
    String str1{ "Hello"};
    String str2{ " World"};
    str1.print();
    str1 += str2;
    str1.print();
    return 0;
}
