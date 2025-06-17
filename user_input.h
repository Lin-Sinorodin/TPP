#ifndef TPP_USER_INPUT_H
#define TPP_USER_INPUT_H

/**
 * Get a number from the user, raises if not a valid number.
 *
 * @param msg Message to print when asking for the number.
 * @return The number typed by the user, as long.
 */
long getNumberFromUser(const std::string& msg);

/**
 * Get a number from the user, raises if not a valid positive number.
 *
 * @param msg Message to print when asking for the number.
 * @return The number typed by the user, as unsigned long.
 */
unsigned long getPositiveNumberFromUser(const std::string& msg);

#endif //TPP_USER_INPUT_H
