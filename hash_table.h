#ifndef TPP_HASH_TABLE_H
#define TPP_HASH_TABLE_H

#include <vector>
#include <string>
#include "linked_list.h"

using std::size_t;
using std::string;
using std::vector;


class HashTable {
public:
    explicit HashTable (size_t size);
    HashTable (const HashTable& other);  // copy constructor
    HashTable& operator=(const HashTable& other);  // copy assignment

    /* Add a pair of key, value to the hash table. */
    void add(const string& key, const string& value);

    /* Check if the given key exists in the keys of the hash table. */
    bool keyExists(const string& key);

    /* Check if the given values exists in the values of the hash table. */
    bool valueExists(const string& value);

    /* Get the value represented by the given key from the hash table. */
    string getByKey(const string& key);

    /* Delete the value represented by the given key from the hash table. */
    void deleteByKey(const string& key);

    /* Increase the size of the table and rearrange all elements according to the new size. */
    void increaseTableSize();

    /* Return the number of the underlying array of the hash table. */
    size_t numElements();

    /* Return the number of the values in the hash table. */
    size_t size();
private:
    /* Underlying array of the hash table. */
    vector<KeyValueList> m_arr;

    /* The maximum allowed value for max(collisions[index]/size), increase size when reached. */
    float m_maxRelativeCollision = 0.1;

    /* Convert a key to an index in the hash table array. */
    size_t keyToIndex(const string& key);

    /* Get the relative collision ratio for the given list, defined by: max(collisions[index]/size). */
    float getRelativeCollision(const KeyValueList& list);
};

#endif //TPP_HASH_TABLE_H
