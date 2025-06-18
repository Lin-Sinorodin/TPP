#ifndef TPP_CALCULATOR_H
#define TPP_CALCULATOR_H

#include <string>

class Calculator {
public:
    /* Add two numbers and return the result: a + b */
    static double add(double a, double b);

    /* Subtract two numbers and return the result: a - b */
    static double subtract(double a, double b);

    /* Multiply two numbers and return the result: a * b */
    static double multiply(double a, double b);

    /* Divide two numbers and return the result: a / b */
    static double divide(double a, double b);

    /**
     * Get a string of the calculation defined by (a op b).
     *
     * @param a First argument of the calculation.
     * @param op The operation to perform on a and b.
     * @param b Second argument of the calculation.
     * @return String of the calculation (a op b).
     */
    static std::string calculationString(double a, char op, double b);

    /**
     * Perform the calculation defined by (a op b) and return the result.
     *
     * @param a First argument of the calculation.
     * @param op The operation to perform on a and b.
     * @param b Second argument of the calculation.
     * @return The result of (a op b)
     */
    static double calculate(double a, char op, double b);
private:
    static constexpr char OPERATION_ADD = '+';
    static constexpr char OPERATION_SUBTRACT = '-';
    static constexpr char OPERATION_MULTIPLY = '*';
    static constexpr char OPERATION_DIVIDE = '/';
};

/**
 * Perform the calculation defined by (a op b) and print the result.
 *
 * This is just a convenience wrapper for Calculator::calculate.
 *
 * @param a First argument of the calculation.
 * @param op The operation to perform on a and b.
 * @param b Second argument of the calculation.
 * @return The result of (a op b)
 */
void calculatePrint(double a, char op, double b);

#endif //TPP_CALCULATOR_H
