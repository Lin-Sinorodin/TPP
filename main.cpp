#include <iostream>
#include <algorithm>

using namespace std;

void q1(string& str, int key) {for_each(str.begin(), str.end(), [key](char& c) {c ^= static_cast<char>(key);});}

void q1Test(int key) {
    string s {"hello"};
    cout << "[Q1] before s = " << s << endl;

    q1(s, key);
    cout << "[Q1] after  s ^ " << key << " = " << s << endl << endl;
}

string q2(string str) {return str;}

void q2Test(const string& s) {
    cout << "[Q2] before s = " << s << endl;
    cout << "[Q2] after  s = " << q2(s) << endl;
}

int main() {
    q1Test(1);
    q2Test("hello");
    return 0;
}
