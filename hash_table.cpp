#include "hash_table.h"

HashTable::HashTable(size_t size) {
    m_arr = vector<KeyValueList>{size, KeyValueList{KeyValue{"", ""}}};
}

HashTable::HashTable(const HashTable &other) {
    m_arr = other.m_arr;  // uses vector copy constructor
}

HashTable &HashTable::operator=(const HashTable& other) {
    m_arr = other.m_arr;  // uses vector copy constructor
    return *this;
}

void HashTable::add(const string& key, const string& value) {
    size_t index = keyToIndex(key);
    KeyValueList list = m_arr.at(index);
    if (!keyExists(key)) {
        m_arr.at(index).emplace_back(key, value);
    }
}

bool HashTable::keyExists(const string &key) {
    size_t index = keyToIndex(key);
    return keyInList(m_arr.at(index), key);
}

bool HashTable::valueExists(const string &value) {
    return std::any_of(m_arr.begin(), m_arr.end(),
                       [&value](const KeyValueList& list) {return valueInList(list, value);});
}

string HashTable::getByKey(const string &key) {
    size_t index = keyToIndex(key);
    return keyToValueFromList(m_arr.at(index), key);
}

void HashTable::deleteByKey(const string &key) {
    size_t index = keyToIndex(key);
    deleteKeyFromList(m_arr.at(index), key);
}

size_t HashTable::numElements() {
    size_t n{0};
    std::for_each(m_arr.begin(), m_arr.end(), [&n](const KeyValueList& list){n += numElementsInList(list);});
    return n;
}

size_t HashTable::size() {
    return m_arr.size();
}

size_t HashTable::keyToIndex(const string &key) {
    size_t key_hash = std::hash<string>{}(key);
    size_t key_index = key_hash % size();
    return key_index;
}
