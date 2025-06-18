#include <iostream>
#include <iomanip>
#include "cli.h"


unsigned int maxElementWidth(const std::vector<int>& arr) {
    auto max_number = std::max_element(arr.begin(), arr.end());
    return static_cast<unsigned int>(std::to_string(*max_number).length());
}

void printPaddedElement(int element, unsigned int width) {
    std::cout << std::setw(static_cast<int>(width)) << std::left << element << ' ';
}

void printNewRowIfNeeded(int current_index, int row_length) {
    // already printed elements_per_row elements, move to next row
    if ((current_index + 1) % row_length == 0) {
        std::cout << std::endl;
    }
}

void printArray(std::vector<int>& arr, int elements_per_row) {
    const unsigned int element_width = maxElementWidth(arr);
    for (int i = 0; i < arr.size(); i++) {
        printPaddedElement(arr[i], element_width);
        printNewRowIfNeeded(i, elements_per_row);
    }
    std::cout << std::endl;
}
