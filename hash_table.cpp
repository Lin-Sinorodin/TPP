#include "hash_table.h"

HashTable::HashTable(size_t size) {
    m_size = size;
    m_arr = vector<KeyValueList>{size, KeyValueList{}};
}

HashTable::HashTable(const HashTable &other) {
    m_size = other.m_size;
    m_arr = other.m_arr;  // uses vector copy constructor
}

HashTable &HashTable::operator=(const HashTable& other) {
    m_size = other.m_size;
    m_arr = other.m_arr;  // uses vector copy constructor
    return *this;
}

void HashTable::add(const string& key, const string& value) {
    // avoid adding keys that already exists, or pairs with empty values
    if (keyExists(key) or key.empty() or value.empty()) {
        return;
    }

    // add the new (key, value) pair at the correct index in the hash table list
    size_t index = keyToIndex(key);
    m_arr.at(index).emplace_back(key, value);

    // check if after adding this element, the table should be resized
    if (getRelativeCollision(m_arr.at(index)) >= m_maxRelativeCollision) {
        increaseTableSize();
    }
}

void HashTable::deleteByKey(const string &key) {
    size_t index = keyToIndex(key);
    deleteKeyFromList(m_arr.at(index), key);
}

void HashTable::increaseTableSize() {
    // update m_size and m_arr
    size_t prev_size = m_size;
    m_size = static_cast<size_t>(prev_size * m_resizeFactor);
    m_arr.resize(m_size, KeyValueList{});

    for (size_t old_index = 0; old_index < prev_size; old_index++) {
        auto l = m_arr.at(old_index).begin();
        while (l != m_arr.at(old_index).end()) {
            string key = l->first;
            string value = l->second;
            size_t new_index = keyToIndex(key);

            if (new_index != old_index) {
                l--;  // move to previous node as the current will be deleted
                m_arr.at(old_index).erase(next(l));
                m_arr.at(new_index).emplace_back(key, value);
            }
            ++l;
        }
    }
}

bool HashTable::keyExists(const string &key) const {
    size_t index = keyToIndex(key);
    return keyInList(m_arr.at(index), key);
}

bool HashTable::valueExists(const string &value) const {
    return std::any_of(m_arr.begin(), m_arr.end(),
                       [&value](const KeyValueList& list) {return valueInList(list, value);});
}

string HashTable::getByKey(const string &key) const {
    size_t index = keyToIndex(key);
    return keyToValueFromList(m_arr.at(index), key);
}

size_t HashTable::numElements() const {
    size_t n{0};
    std::for_each(m_arr.begin(), m_arr.end(), [&n](const KeyValueList& list){n += list.size();});
    return n;
}

size_t HashTable::size() const {
    return m_size;
}

size_t HashTable::keyToIndex(const string &key) const {
    size_t key_hash = std::hash<string>{}(key);
    size_t key_index = key_hash % m_size;
    return key_index;
}

float HashTable::getRelativeCollision(const KeyValueList &list) const {
    return static_cast<float>(list.size()) / static_cast<float>(m_size);
}
