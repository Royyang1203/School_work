#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <climits>

using namespace std;

bool make_map(string str, vector<vector<int>> &m)
{

    str.erase(0, 4);
    // cout << str << endl;
    int row = 0, col = 0;
    vector<int> temp;
    for (int i = 0; i < str.size(); ++i)
    {
        switch (str[i])
        {
        case '[':
        case ',':
            break;
        case ']':
            m.push_back(temp);
            temp.clear();
            row = 0;
            col += 1;
            break;
        default:
            temp.push_back(str[i] - '0');
        }
    }
    return true;
}

void remove_minefield(int r, int c, vector<vector<int>> &m)
{
    if (r < 0 || c < 0 || r >= m.size() || c >= m[r].size())
        return;
    if (!m[r][c])
        return;
    m[r][c] = 0;
    int dir_i[4] = {-1, 1, 0, 0};
    int dir_j[4] = {0, 0, -1, 1};
    for (int i = 0; i < 4; ++i)
    {
        remove_minefield(r + dir_i[i], c + dir_j[i], m);
    }
}

int main()
{
    cout << "Input: ";
    string input;
    getline(cin, input);
    while (input.substr(input.size() - 2, input.size()) != "]]")
    {
        string t;
        getline(cin, t);
        input = input + t;
        input.erase(remove(input.begin(), input.end(), ' '), input.end());
    }
    vector<vector<int>> m;
    // cout << input << endl;
    // cout << input.size() << endl;

    make_map(input, m);

    // for (auto row : m)
    // {
    //     int j = 0;
    //     for (auto val : row)
    //     {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }
    int res = 0;
    int i = 0;
    for (auto row : m)
    {
        int j = 0;
        for (auto val : row)
        {
            if (m[i][j])
            {
                remove_minefield(i, j, m);
                res++;
            }
            ++j;
        }
        ++i;
    }
    cout << "Output: " << res;
}

// map = [[0,1,1,0,0]
//       [1,1,0,1,1]
//       [0,0,1,0,0]
//       [0,0,1,1,0]]

// map=[[0,1,1,0,0][1,1,0,1,1][0,0,1,0,0][0,0,1,1,0]]

// map=[[0,1,1,0,0,0,1]
//      [1,1,0,1,1,0,0]
//      [0,0,1,0,0,1,0]
//      [0,0,1,1,0,1,0]]
