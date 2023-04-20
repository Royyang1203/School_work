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

bool make_map(string str, vector<vector<int>> &m)
{
    int row = 0, col = 0;

    str.erase(0, 4);
    // cout << str << endl;
    string matches("0123456789");
    size_t offset = str.find_first_of(matches);
    string next(str.substr(offset));

    stringstream intStream(next);
    intStream >> row;
    str.erase(0, str.find("]") + 2);

    offset = str.find_first_of(matches);
    next = str.substr(offset);

    stringstream intStream2(next);
    intStream2 >> col;
    str.erase(0, str.find("]") + 2);
    // cout << row << ":" << col << endl;

    int k = 0;
    vector<int> temp;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            while (str[k] != '1' && str[k] != '0')
                ++k;
            // cout << k << endl;
            temp.push_back(str[k] - '0');
            ++k;
        }
        m.push_back(temp);
        temp.clear();
    }
    return true;
}

int remove_minefield(int r, int c, vector<vector<int>> &m, int n)
{
    if (r < 0 || c < 0 || r >= m.size() || c >= m[r].size())
        return n;
    if (!m[r][c])
        return n;
    m[r][c] = 0;
    int dir_i[4] = {-1, 1, 0, 0};
    int dir_j[4] = {0, 0, -1, 1};
    for (int i = 0; i < 4; ++i)
    {
        n = remove_minefield(r + dir_i[i], c + dir_j[i], m, n);
    }
    return n + 1;
}

int main()
{
    // cout << "Input: ";
    string input;
    getline(cin, input);
    while (input.substr(input.size() - 2, input.size()) != "};")
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
    int max = 0;
    int i = 0;
    for (auto row : m)
    {
        int j = 0;
        for (auto val : row)
        {
            if (m[i][j])
            {
                int t = remove_minefield(i, j, m, 0);
                res++;
                if (t > max)
                    max = t;
                // cout << t << endl;
            }
            ++j;
        }
        ++i;
    }
    cout << max;
}

// map[4][5] = {
// 0, 1, 1, 0, 0,
// 1, 1, 0, 1, 1,
// 0, 0, 1, 0, 0,
// 0, 0, 1, 1, 0
// };

// map[4][6] = {
// 0, 1, 1, 1, 0, 1,
// 1, 1, 0, 1, 1, 0,
// 0, 0, 1, 0, 0, 1,
// 0, 0, 1, 1, 0, 1
// };
