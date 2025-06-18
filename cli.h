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
 * @param current_index The index of the current element in the array.
 * @param row_length The specified row length, if element is at the end of the row than print new line.
 */
void printNewRowIfNeeded(int current_index, int row_length);

/**
 * Print the given array of integers in order, with limited number of elements per row.
 *
 * @param arr A pointer to an array of integers.
 * @param elements_per_row The maximum number of elements per row in the printed output.
 */
void printArray(std::vector<int>& arr, int elements_per_row);

#endif //TPP_CLI_H
