#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 1 - initialize a vector (v1)
    vector<int> v1 {1, 2, 3, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    // 2 - count number of elements that equal to 4
    cout << "Q2: " << count(v1.begin(), v1.end(), 4) << endl;

    // 3 - count number of elements larger than 4
    cout << "Q3: " << count_if(v1.begin(), v1.end(), [](int i) {return i > 4;}) << endl;

    // 4 - remove elements smaller than 8 from the vector
    v1.erase(remove_if(v1.begin(), v1.end(), [](int i) {return i < 8;}), v1.end());

    // 5 - print v1
    copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));

    // 6 - initialize a new empty vector (v2)
    vector<int> v2 {};

    // 7 - fill v2 with the difference between values from v1

    // 8 - print v2

    // 9 - print the sum of all elements in v2

    return 0;
}
