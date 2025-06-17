#include <iostream>
#include <iomanip>

void printMultiplicationTable(int size) {
    char sep[] = " ";

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            std::cout << std::setw(3) << std::left << i * j << sep;
        }
        std::cout << std::endl;
    }
}

int main() {
    int size = 11;
    std::cout << "Multiplication table up to " << size << ":" << std::endl;
    printMultiplicationTable(size);
    return 0;
}
