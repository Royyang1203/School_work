#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <climits>
#include <sstream>

using namespace std;
int main()
{
    string str = "1234][3434";
    cout << str << endl;
    auto position = str.find("]");
    cout << position << endl;
    string matches("0123456789");
    size_t offset = str.find_first_of(matches);
    string next(str.substr(offset));

    stringstream intStream(next);
    int intValue;
    intStream >> intValue;
    cout << intValue << endl;
    str.erase(0, str.find("]") + 2);
    cout << str << endl;
}