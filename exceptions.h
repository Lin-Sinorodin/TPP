#ifndef TPP_EXCEPTIONS_H
#define TPP_EXCEPTIONS_H

#include <exception>
#include <string>
#include <string_view>

/* Exception for invalid calculator operation */
class InvalidOperationException : public std::exception {
private:
    std::string m_error{};
public:
    explicit InvalidOperationException(std::string_view error) : m_error{error} {}
    [[nodiscard]] const char* what() const noexcept override { return m_error.c_str(); }
};

/* Exception for calculator zero division */
class ZeroDivisionException : public std::exception {
private:
    std::string m_error{};
public:
    explicit ZeroDivisionException(std::string_view error) : m_error{error} {}
    [[nodiscard]] const char* what() const noexcept override { return m_error.c_str(); }
};

#endif //TPP_EXCEPTIONS_H
