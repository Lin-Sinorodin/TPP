#include "exceptions.h"

const char *InvalidOperationException::what() const noexcept {
    return m_error.c_str();
}

const char *ZeroDivisionException::what() const noexcept {
    return m_error.c_str();
}
