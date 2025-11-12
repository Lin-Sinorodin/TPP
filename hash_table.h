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

    /* Delete the value represented by the given key from the hash table. */
    void deleteByKey(const string& key);

    /* Increase the size of the table and rearrange all elements according to the new size. */
    void increaseTableSize();

    /* Check if the given key exists in the keys of the hash table. */
    [[nodiscard]] bool keyExists(const string& key) const;

    /* Check if the given values exists in the values of the hash table. */
    [[nodiscard]] bool valueExists(const string& value) const;

    /* Get the value represented by the given key from the hash table. */
    [[nodiscard]] string getByKey(const string& key) const;

    /* Return the number of (key, value) pairs in the hash table. */
    [[nodiscard]] size_t numElements() const;

    /* Return the size of the underlying array of the hash table. */
    [[nodiscard]] size_t size() const;
private:
    /* Size of the underlying array of the hash table. */
    size_t m_size;

    /* Underlying array of the hash table. */
    vector<KeyValueList> m_arr;

    /* The maximum allowed value for max(collisions[index]/size), increase size when reached. */
    float m_maxRelativeCollision = 0.5;

    /* The multiplier of the new array size when resizing (new_size = m_resizeFactor * old_size) */
    double m_resizeFactor = 2.0;

    /* Convert a key to an index in the hash table array. */
    [[nodiscard]] size_t keyToIndex(const string& key) const;

    /* Get the relative collision ratio for the given list, defined by: collisions/size (collisions = list size). */
    [[nodiscard]] float getRelativeCollision(const KeyValueList& list) const;
};

#endif //TPP_HASH_TABLE_H
