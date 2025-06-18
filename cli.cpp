#include <iostream>
#include <iomanip>
#include "cli.h"


unsigned int maxElementWidth(const std::vector<int>& arr) {
    auto maxNumber = std::max_element(arr.begin(), arr.end());
    return static_cast<unsigned int>(std::to_string(*maxNumber).length());
}

void printPaddedElement(int element, unsigned int width) {
    std::cout << std::setw(static_cast<int>(width)) << std::left << element << ' ';
}

void printNewRowIfNeeded(int currentIndex, int rowLength) {
    // already printed elements_per_row elements, move to next row
    if ((currentIndex + 1) % rowLength == 0) {
        std::cout << std::endl;
    }
}

void printArray(std::vector<int>& arr, int elementsPerRow) {
    const unsigned int elementWidth = maxElementWidth(arr);
    for (int i = 0; i < arr.size(); i++) {
        printPaddedElement(arr[i], elementWidth);
        printNewRowIfNeeded(i, elementsPerRow);
    }
    std::cout << std::endl;
}
