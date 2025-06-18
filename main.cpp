#include <iostream>
#include "imaginary.h"

#define PREFIX "\t> "

void example1() {
    std::string name = "num1";
    Imaginary num{};
    std::cout << "\nImaginary " << name << "{};\n";
    num.print(name, PREFIX);
    std::cout << '\n';
}

void example2() {
    std::string name = "num2";
    Imaginary num{1, 2};
    std::cout << "Imaginary " << name << "{1, 2};\n";
    num.print(name, PREFIX);

    num.setReal(10);
    num.setImag(20);
    std::cout <<  name << ".setReal(10);\n" << name << ".setImag(20);\n";
    num.print(name, PREFIX);

    num += num;
    std::cout <<  name << " += " << name << '\n';
    num.print(name, PREFIX);
    std::cout << '\n';
}

void example3() {
    Imaginary num1{1, 0};
    Imaginary num2{0, 1};
    Imaginary num3{0, 1};
    std::cout << "Imaginary num1{1, 0};\n";
    std::cout << "Imaginary num2{0, 1};\n";
    std::cout << "Imaginary num3{0, 1};\n";
    num1.print("num1", PREFIX);
    num2.print("num2", PREFIX);
    num2.print("num3", PREFIX);
    std::cout << '\n';

    bool eq;
    eq = num1 == num2;
    std::cout << PREFIX << "num1 == num2 " << (eq ? "True" : "False") << '\n';
    eq = num2 == num3;
    std::cout << PREFIX << "num2 == num3 " << (eq ? "True" : "False") << '\n';
    std::cout << '\n';

    Imaginary temp{};
    temp = num1 + num2;
    temp.print("num1 + num2", PREFIX);
    temp = num1 - num2;
    temp.print("num1 - num2", PREFIX);
    temp = num1 * num2;
    temp.print("num1 * num2", PREFIX);

}


int main() {
    example1();
    example2();
    example3();

    return 0;
}
