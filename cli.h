#ifndef TPP_CLI_H
#define TPP_CLI_H

#include <vector>

/**
 * Return the width (number of digits) of the largest value in the given integer array.
 *
 * @param arr A vector with integers.
 * @return The number of bits of the largest value.
 */
unsigned int maxElementWidth(const std::vector<int>& arr);

/**
 * Prints the given element, justified to the left, padded with spaces to the given width.
 *
 * @param element The integer element to print, justified to the left.
 * @param width The padding width to print.
 */
void printPaddedElement(int element, unsigned int width);

/**
 * Check if the given index is at the end of the row specified by row_length, print new line if it is.
 *
 * @param currentIndex The index of the current element in the array.
 * @param rowLength The specified row length, if element is at the end of the row than print new line.
 */
void printNewRowIfNeeded(int currentIndex, int rowLength);

/**
 * Print the given array of integers in order, with limited number of elements per row.
 *
 * @param arr A pointer to an array of integers.
 * @param elementsPerRow The maximum number of elements per row in the printed output.
 */
void printArray(std::vector<int>& arr, int elementsPerRow);

#endif //TPP_CLI_H
