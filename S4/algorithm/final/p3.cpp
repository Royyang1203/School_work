// utf-8
#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <climits>

using namespace std;

string minWindow(string s, string p)
{
    if (s.size() < p.size() || p.size() == 0)
        return "";
    // 先記錄 p 中所有字母出現次數
    map<char, int> mp;
    for (int i = 0; i < p.length(); i++)
    {
        mp[p[i]]++;
    }

    int count = mp.size();
    int i = 0, j = 0, len = INT_MAX;
    pair<int, int> ans;

    while (j < s.length())
    {
        if (mp.find(s[j]) != mp.end()) // key exist
        {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
            {
                count--;
            }
        }
        if (count == 0) // 為一組符合條件的解
        {
            // 比較此解是否較先前的解更優
            // 試著減少解減少解字串之長度
            while (count == 0)
            {
                if (j - i + 1 < len) // 更新最優解
                {
                    len = j - i + 1;
                    ans = {i, len};
                }
                if (mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]++;
                    if (mp[s[i]] == 1)
                    {
                        count++;
                    }
                }
                i++;
            }
        }
        j++;
    }
    return len == INT_MAX ? "" : s.substr(ans.first, ans.second);
}

void make_str(string &str, string &s, string &t)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    str.erase(0, 3);
    // cout << str << endl;
    // cout << str.find('\"') << endl;
    s = str.substr(0, str.find('\"'));
    str.erase(0, str.find('\"') + 5);
    // cout << str << endl;
    t = str.substr(0, str.find('\"'));
}

int main()
{
    cout << "Input: ";
    string s, t;
    string input;
    getline(cin, input);
    // string input = "s = \"xxxxyxyyyzyzzzz\", t = \"zzxxy\"";
    // string input = "s = \"gocodeiscool\", t = \"goose\"";
    // string input = "s = \"abcdefg\", t = \"cdex\"";
    // cout << input << endl;
    make_str(input, s, t);
    // cout << s << " " << t << endl;

    cout << "Output: " << '\"' << minWindow(s, t) << '\"' << endl;
    return 0;
}

// s = "gocodeiscool", t = "goose"

// s = "xxxxyxyyyzyzzzz", t = "zzxxy"

// s = "abcdefg", t = "cdex"