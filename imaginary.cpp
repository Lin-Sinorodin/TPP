#include <iostream>
#include "imaginary.h"

/*
 * ------------------------------------------------ Setters and getters ------------------------------------------------
 */

long Imaginary::real() const {
    return m_real;
}

long Imaginary::imag() const {
    return m_imag;
}

void Imaginary::setReal(long real) {
    m_real = real;
}

void Imaginary::setImag(long imag) {
    m_imag = imag;
}

/*
 * ----------------------------------------------------- Operators -----------------------------------------------------
 */

bool operator==(Imaginary lhs, const Imaginary &rhs) {
    return std::tie(lhs.m_real, lhs.m_imag) == std::tie(rhs.m_real, rhs.m_imag);
}

Imaginary &Imaginary::operator+=(const Imaginary &rhs) {
    // z1 + z2  =  (a + bi) + (c + di)  =  (a + c) + (b + d)i
    m_real += rhs.m_real;
    m_imag += rhs.m_imag;
    return *this;
}

Imaginary operator+(Imaginary lhs, const Imaginary &rhs) {
    lhs += rhs;
    return lhs;
}

Imaginary &Imaginary::operator-=(const Imaginary &rhs) {
    // z1 – z2  =  (a + bi) - (c + di)  =  (a - c) + (b - d)i
    m_real -= rhs.m_real;
    m_imag -= rhs.m_imag;
    return *this;
}

Imaginary operator-(Imaginary lhs, const Imaginary &rhs) {
    lhs -= rhs;
    return lhs;
}

Imaginary &Imaginary::operator*=(const Imaginary &rhs) {
    // z1 * z2  =  (a + bi) * (c + di)  =  (ac - bd) + (ad + bc)i
    long new_real = m_real * rhs.m_real - m_imag * rhs.m_imag;
    long new_imag = m_real * rhs.m_imag + m_imag * rhs.m_real;
    m_real = new_real;
    m_imag = new_imag;
    return *this;
}

Imaginary operator*(Imaginary lhs, const Imaginary &rhs) {
    lhs *= rhs;
    return lhs;
}

/*
 * -------------------------------------------------------- Misc -------------------------------------------------------
 */

void Imaginary::print(const std::string &name, const std::string &prefix) const {
    if (!name.empty()) {
        // <prefix> name = a + bi
        std::cout << prefix << name << " = " << m_real << " + " << m_imag << "i\n";
    } else {
        // <prefix> a + bi
        std::cout << prefix << m_real << " + " << m_imag << "i\n";
    }
}
