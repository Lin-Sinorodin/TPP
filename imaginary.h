#ifndef TPP_IMAGINARY_H
#define TPP_IMAGINARY_H

#include <string>

class Imaginary {
private:
    long m_real;
    long m_imag;
public:
    /*
     * -------------------------------------------------- Constructors -------------------------------------------------
     */

    explicit Imaginary () : m_real(0), m_imag(0) {}
    explicit Imaginary (long real, long imag) : m_real(real), m_imag(imag) {}

    /*
     * ---------------------------------------------- Setters and getters ----------------------------------------------
     */

    /* Get the real value of the imaginary number. */
    [[nodiscard]] long real() const;
    /* Get the imaginary value of the imaginary number. */
    [[nodiscard]] long imag() const;
    /* Set the real value of the imaginary number. */
    void setReal(long real);
    /* Set the imaginary value of the imaginary number. */
    void setImag(long imag);

    /*
     * --------------------------------------------------- Operators ---------------------------------------------------
     */

    /* Imaginary numbers equality: z1 == z2  <==>  (a + bi) == (c + di)  <==>  (a == c) and (b == d) */
    friend bool operator==(Imaginary lhs, const Imaginary& rhs);

    /* Imaginary numbers addition: z1 + z2  =  (a + bi) + (c + di)  =  (a + c) + (b + d)i */
    Imaginary& operator+=(const Imaginary& rhs);
    /* Imaginary numbers addition: z1 + z2  =  (a + bi) + (c + di)  =  (a + c) + (b + d)i */
    friend Imaginary operator+(Imaginary lhs, const Imaginary& rhs);

    /* Imaginary numbers subtraction: z1 – z2  =  (a + bi) - (c + di)  =  (a - c) + (b - d)i */
    Imaginary& operator-=(const Imaginary& rhs);
    /* Imaginary numbers subtraction: z1 – z2  =  (a + bi) - (c + di)  =  (a - c) + (b - d)i */
    friend Imaginary operator-(Imaginary lhs, const Imaginary& rhs);

    /* Imaginary numbers multiplication: z1 * z2  =  (a + bi) * (c + di)  =  (ac - bd) + (ad + bc)i */
    Imaginary& operator*=(const Imaginary& rhs);
    /* Imaginary numbers multiplication: z1 * z2  =  (a + bi) * (c + di)  =  (ac - bd) + (ad + bc)i */
    friend Imaginary operator*(Imaginary lhs, const Imaginary& rhs);

    /*
     * ------------------------------------------------------ Misc -----------------------------------------------------
     */

    /**
     * Print the imaginary number to the standard output.
     *
     * The print format can be one of 2 options:
     *      1. If name is not an empty string, print: <prefix> name = a + bi
     *      2. If name is an empty string, print: <prefix> a + bi
     * ( If prefix is empty string it won't be printed)
     *
     *
     * @param name Optional name, default is no name;
     * @param prefix Optional prefix, default is no prefix;
     */
    void print(const std::string& name = "", const std::string& prefix = "") const;
};

#endif //TPP_IMAGINARY_H
