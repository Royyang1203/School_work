#include <iostream>
#include <string>

using namespace std;

bool palindrome_1(string s)
{
    bool res = true;
    for (int i = 0; i < s.size() / 2; ++i)
        if (s[i] != s[s.size() - 1 - i])
            res = false;
    return res;
}

bool palindrome_2(string s)
{
    for (int i = 0; i < s.size() / 2; ++i)
        if (s[i] != s[s.size() - 1 - i])
            return false;
    return true;
}

int main()
{
    string s;
    cin >> s;
    cout << palindrome_1(s);
    return 0;
}