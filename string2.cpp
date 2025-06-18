
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

std::size_t cStringLen(const char* cString) {
    int length = 0;
    while (cString[length] != '\0') {
        length++;
    }
    return static_cast<std::size_t>(length);
}
