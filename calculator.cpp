#include <iostream>
#include "calculator.h"
#include "exceptions.h"

double Calculator::add(double a, double b) {
    return a + b;
}

double Calculator::subtract(double a, double b) {
    return a - b;
}

double Calculator::multiply(double a, double b) {
    return a * b;
}

double Calculator::divide(double a, double b) {
    if (b == 0) {
        throw ZeroDivisionException("divided by zero");
    }
    return a / b;
}

double Calculator::calculate(double a, char op, double b) {
    switch (op) {
        case OP_ADD:
            return Calculator::add(a, b);
        case OP_SUBTRACT:
            return Calculator::subtract(a, b);
        case OP_MULTIPLY:
            return Calculator::multiply(a, b);
        case OP_DIVIDE:
            return Calculator::divide(a, b);
        default:
            throw InvalidOperationException("unknown operation");
    }
}

void Calculator::calculatePrint(double a, char op, double b) {
    try {
        double res = Calculator::calculate(a, op, b);
        std::cout << a << ' ' << op << ' ' << b << " = " << res << '\n';
    } catch (const InvalidOperationException& exception) {
        std::cout << "[!] Unknown operation: " << a << ' ' << op << ' ' << b << '\n';
    } catch (const ZeroDivisionException& exception) {
        std::cout << "[!] Zero division: " << a << ' ' << op << ' ' << b << '\n';
    } catch (const std::exception& exception) {
        std::cout << "[!] Exception (" << exception.what() << "):" << a << ' ' << op << ' ' << b << '\n';
    }
}
