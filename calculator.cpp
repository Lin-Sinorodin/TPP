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
        std::string error = "zero division: " + calculationString(a, OPERATION_DIVIDE, b);
        throw ZeroDivisionException(error);
    }
    return a / b;
}

std::string Calculator::calculationString(double a, char op, double b) {
    return std::to_string(a) + " " + op + " " + std::to_string(b);
}

double Calculator::calculate(double a, char op, double b) {
    switch (op) {
        case OPERATION_ADD:
            return Calculator::add(a, b);
        case OPERATION_SUBTRACT:
            return Calculator::subtract(a, b);
        case OPERATION_MULTIPLY:
            return Calculator::multiply(a, b);
        case OPERATION_DIVIDE:
            return Calculator::divide(a, b);
        default:
            std::string error = "unknown operation: " + calculationString(a, op, b);
            throw InvalidOperationException(error);
    }
}

void calculatePrint(double a, char op, double b) {
    try {
        const double res = Calculator::calculate(a, op, b);
        std::cout << a << ' ' << op << ' ' << b << " = " << res << '\n';
    } catch (const InvalidOperationException& exception) {
        std::cerr << exception.what() << '\n';
    } catch (const ZeroDivisionException& exception) {
        std::cerr << exception.what() << '\n';
    } catch (const std::exception& exception) {
        std::string calculation = Calculator::calculationString(a, op, b);
        std::cerr << "[!] Exception (" << exception.what() << "):" << calculation << '\n';
    }
}
