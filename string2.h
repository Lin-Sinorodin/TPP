#ifndef TPP_STRING2_H
#define TPP_STRING2_H

class String {
public:
    explicit String ();
    explicit String (const char cString[]);
    ~String ();

    void print();
private:
    char* m_string;
    std::size_t m_size;
};

/* Calculate the length of a C style string. */
std::size_t cStringLen(const char* cString);

#endif //TPP_STRING2_H
