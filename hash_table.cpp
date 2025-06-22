#include "hash_table.h"

HashTable::HashTable(std::size_t size) {
    m_arr = std::vector<std::string>{size, ""};
}

HashTable::HashTable(const HashTable &other) {
    m_arr = other.m_arr;  // uses vector copy constructor
}

HashTable &HashTable::operator=(const HashTable& other) {
    m_arr = other.m_arr;  // uses vector copy constructor
    return *this;
}

void HashTable::add(const std::string& key, const std::string& value) {
    m_arr.at(keyToIndex(key)) = value;
}

bool HashTable::keyExists(const std::string &key) {
    return not m_arr.at(keyToIndex(key)).empty();
}

bool HashTable::valueExists(const std::string &value) {
    for (const auto& elem: m_arr) {
        if (elem == value) {
            return true;
        }
    }
    return std::any_of(m_arr.begin(), m_arr.end(), [&value](std::string& s) {return value == s;});
}

std::string HashTable::getByKey(const std::string &key) {
    return m_arr.at(keyToIndex(key));
}

void HashTable::deleteByKey(const std::string &key) {
    m_arr.at(keyToIndex(key)) = "";
}

std::size_t HashTable::numElements() {
    return std::count_if(m_arr.begin(), m_arr.end(), [](std::string& s) {return not s.empty();});
}

std::size_t HashTable::size() {
    return m_arr.size();
}

std::size_t HashTable::keyToIndex(const std::string &key) {
    std::size_t key_hash = std::hash<std::string>{}(key);
    std::size_t key_index = key_hash % size();
    return key_index;
}
