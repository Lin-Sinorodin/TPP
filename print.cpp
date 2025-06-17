#include <iostream>
#include <iomanip>
#include "print.h"


int maxElementWidth(std::vector<int>& arr) {
    auto max_number = std::max_element(arr.begin(), arr.end());
    return static_cast<int>(std::to_string(*max_number).length());
}


void printJustifiedElement(int element, int width) {
    std::cout << std::setw(width) << std::left << element << ' ';
}

void printNewRowIfNeeded(int curr_index, int row_length) {
    // already printed elements_per_row elements, move to next row
    if ((curr_index + 1) % row_length == 0) {
        std::cout << '\n';
    }
}

void printArray(std::vector<int>& arr, int elements_per_row) {
    const int element_width = maxElementWidth(arr);
    for (int i = 0; i < arr.size(); i++) {
        printJustifiedElement(arr[i], element_width);
        printNewRowIfNeeded(i, elements_per_row);
    }
    std::cout << '\n';
}
