#include <iostream>
#include <iomanip>
#include <string>

#define SIZE 11
#define SEP " "

/**
 * Print the multiplication table from 1 * 1 up to size * size.
 *
 * @param size The max value of the table.
 */
void printMultiplicationTable(unsigned int size, const std::string& sep) {
    static int width = static_cast<int>(std::to_string(size * size).length());

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            std::cout << std::setw(width) << std::left << i * j << sep;
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "Multiplication table up to " << SIZE << ":\n";
    printMultiplicationTable(SIZE, SEP);
    return 0;
}
