#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <climits>

using namespace std;

bool comp(string &s1, string &s2)
{
    return s1 + s2 > s2 + s1;
}

string largestNumber(vector<string> &v)
{

    // sort the string
    sort(v.begin(), v.end(), comp);

    // generate the result
    string result;
    for (int i = 0; i < v.size(); i++)
    {
        result += v[i];
    }

    // special case: start with zero (e.g. [0, 0])
    if (result[0] == '0')
        return "0";

    return result;
}

void make_arr(string &str, vector<string> &num)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    str.erase(0, 6);
    while (str.find(',') != str.npos)
    {
        num.push_back(str.substr(0, str.find(',')));
        str.erase(0, str.find(',') + 1);
    }
    num.push_back(str.substr(0, str.find(']')));
}

int main()
{
    cout << "Input: ";

    string input;
    getline(cin, input);
    vector<string> num;
    make_arr(input, num);

    cout << "Output: " << '\"' << largestNumber(num) << '\"' << endl;
}
// nums = [1, 23, 456, 789, 101112]

// nums = [1, 2, 3, 4, 5]

// nums = [0, 0, 0]