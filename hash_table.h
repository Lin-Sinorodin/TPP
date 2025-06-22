#ifndef TPP_HASH_TABLE_H
#define TPP_HASH_TABLE_H

#include <cstdlib>
#include <vector>
#include <optional>
#include <string>

class HashTable {
public:
    explicit HashTable (std::size_t size);
    HashTable (const HashTable& other);  // copy constructor
    HashTable& operator=(const HashTable& other);  // copy assignment

    /* Add a pair of key, value to the hash table. */
    void add(const std::string& key, const std::string& value);

    /* Check if the given key exists in the keys of the hash table. */
    bool keyExists(const std::string& key);

    /* Check if the given values exists in the values of the hash table. */
    bool valueExists(const std::string& value);

    /* Get the value represented by the given key from the hash table. */
    std::string getByKey(const std::string& key);

    /* Delete the value represented by the given key from the hash table. */
    void deleteByKey(const std::string& key);

    /* Return the number of the underlying array of the hash table. */
    std::size_t numElements();

    /* Return the number of the values in the hash table. */
    std::size_t size();
private:
    /* Underlying array of the hash table. */
    std::vector<std::string> m_arr;

    /* Convert a key to an index in the hash table array. */
    std::size_t keyToIndex(const std::string& key);
};

#endif //TPP_HASH_TABLE_H
