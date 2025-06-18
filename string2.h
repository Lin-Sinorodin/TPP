#ifndef TPP_STRING2_H
#define TPP_STRING2_H

class String {
public:
    explicit String ();
    explicit String (const char cString[]);
    ~String ();

    /* Returns the length of the string, in terms of bytes. */
    [[nodiscard]] std::size_t length() const noexcept;

    /* Returns whether the string is empty (i.e. whether its length is 0). */
    [[nodiscard]] bool empty() const noexcept;

    /* Erases the contents of the string, which becomes an empty string (with a length of 0 characters). */
    void clear() noexcept;

    /* Array like access to the string (reading and writing)*/
    char& operator[](std::size_t idx);
    /* Const-array like access to the string (only reading) */
    const char& operator[](std::size_t idx) const;

    void print();
private:
    char* m_string;
    std::size_t m_size;
};

/* Calculate the length of a C style string. */
std::size_t cStringLen(const char* cString);

#endif //TPP_STRING2_H
