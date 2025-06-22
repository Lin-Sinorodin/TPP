#include <iostream>
#include <algorithm>

using namespace std;

void q1(string& str, int key) {for_each(str.begin(), str.end(), [key](char& c) {c ^= static_cast<char>(key);});}

void q1Test(int key) {
    string s {"hello"};
    cout << "[Q1] before s = " << s << endl;

    q1(s, key);
    cout << "[Q1] after  s ^ " << key << " = " << s << endl;

}

int main() {
    q1Test(1);
    return 0;
}
