#include "calculator.h"


int main() {
    Calculator::calculatePrint(15, '+', 7);
    Calculator::calculatePrint(10, '-', 80);
    Calculator::calculatePrint(71, '*', 49);
    Calculator::calculatePrint(49, '/', 71);
    Calculator::calculatePrint(15, '@', 7);
    Calculator::calculatePrint(15, '/', 0);
    return 0;
}
