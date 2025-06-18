
#include <iostream>
#include "string2.h"

String::String() {
    m_string = new char[]{};
    m_size = 0;
}

String::String(const char cString[]) {
    m_size = cStringLen(cString);
    m_string = new char[m_size]{};
    std::cout << "Allocated string with size: " << m_size << std::endl;
    for (int i = 0; i < m_size; i ++) {
        m_string[i] = cString[i];
    }
}

String::~String() {
    delete[] m_string;
    std::cout << "Deallocated string\n";
}

void String::print() {
    for (int i = 0; i < m_size; i++) {
        std::cout << m_string[i];
    }
    std::cout << std::endl;
}

std::size_t String::length() const noexcept {
    return m_size;
}

bool String::empty() const noexcept {
    return m_size == 0;
}

void String::clear() noexcept {
    delete[] m_string;
    m_string = new char[]{};
    m_size = 0;
}

char &String::operator[](std::size_t idx) {
    return m_string[idx];
}

const char &String::operator[](std::size_t idx) const {
    return m_string[idx];
}

String &String::operator+=(const String &rhs) {
    std::size_t new_m_size = m_size + rhs.m_size;
    char* new_m_string = new char[new_m_size]{};
    memcpy(new_m_string, m_string, m_size);
    memcpy(new_m_string + m_size, rhs.m_string, rhs.m_size);
    delete[] m_string;
    m_string = new_m_string;
    m_size = new_m_size;
    return *this;
}

std::size_t cStringLen(const char* cString) {
    int length = 0;
    while (cString[length] != '\0') {
        length++;
    }
    return static_cast<std::size_t>(length);
}
