#ifndef TPP_CALCULATOR_H
#define TPP_CALCULATOR_H

#define OP_ADD '+'
#define OP_SUBTRACT '-'
#define OP_MULTIPLY '*'
#define OP_DIVIDE '/'


class Calculator {
private:
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
     * Perform the calculation defined by (a op b) and return the result.
     *
     * @param a First argument of the calculation.
     * @param op The operation to perform on a and b.
     * @param b Second argument of the calculation.
     * @return The result of (a op b)
     */
    static double calculate(double a, char op, double b);

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
    static void calculatePrint(double a, char op, double b);
};

#endif //TPP_CALCULATOR_H
