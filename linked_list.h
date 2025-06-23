#ifndef TPP_LINKED_LIST_H
#define TPP_LINKED_LIST_H

#include <string>
#include <list>
#include <utility>

using std::string;

/* An element in the linked list with key and value, format: (key, value) */
using KeyValue = std::pair<string, string>;

/* A linked list with elements consists of key and value, format: (key, value) -> (key, value) -> ... */
using KeyValueList = std::list<KeyValue>;

/* Return whether the key is inside the given KeyValue list. */
bool keyInList(const KeyValueList& list, const string& key);

/* Return whether the value is inside the given KeyValue list. */
bool valueInList(const KeyValueList& list, const string& value);

/* Return value of the given key at the given KeyValue list. */
string keyToValueFromList(const KeyValueList& list, const string& key);

/* Delete the KeyValue pair with given key from the given KeyValue list. */
void deleteKeyFromList(KeyValueList &list, const string& key);

#endif //TPP_LINKED_LIST_H
