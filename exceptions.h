#ifndef TPP_EXCEPTIONS_H
#define TPP_EXCEPTIONS_H

#include <exception>
#include <string>
#include <utility>

/* Exception for invalid calculator operation */
class InvalidOperationException : public std::exception {
public:
    explicit InvalidOperationException(std::string error) : m_error{std::move(error)} {}
    [[nodiscard]] const char* what() const noexcept override;
private:
    std::string m_error;
};

/* Exception for calculator zero division */
class ZeroDivisionException : public std::exception {
public:
    explicit ZeroDivisionException(std::string error) : m_error{std::move(error)} {}
    [[nodiscard]] const char* what() const noexcept override;
private:
    std::string m_error;
};

#endif //TPP_EXCEPTIONS_H
