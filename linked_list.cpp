#include "linked_list.h"

using std::any_of;
using std::find_if;

std::size_t numElementsInList(const KeyValueList &list) {
    return std::count_if(list.begin(), list.end(), [](const KeyValue& kv) {return !kv.first.empty();});
}

bool keyInList(const KeyValueList& list, const string &key) {
    return any_of(list.begin(), list.end(),
                  [&key](const KeyValue& kv) {return kv.first == key;});
}

bool valueInList(const KeyValueList &list, const string &value) {
    return any_of(list.begin(), list.end(),
                  [&value](const KeyValue& kv) {return kv.second == value;});
}

string keyToValueFromList(const KeyValueList &list, const string &key) {
    const auto it = find_if(list.begin(), list.end(),
                            [&key](const KeyValue& kv) {return kv.first == key;});
    if (it != list.end()) {
        return it->second;
    }
    return "";
}

void deleteKeyFromList(KeyValueList &list, const string &key) {
    list.erase(find_if(list.begin(), list.end(),
                       [&key](const KeyValue& kv) {return kv.first == key;}), list.end());
}
