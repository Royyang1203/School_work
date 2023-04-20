#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool make_map(string str, vector<vector<int>> &m)
{
    if (str.substr(0, 5) != "map=[")
        return false;
    int row = 0, col = 0;
    vector<int> temp;
    for (int i = 5; str[i] != '\10'; ++i)
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
    string input;
    cin >> input;
    vector<vector<int>> m;

    make_map(input, m);

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
    cout << res;
}
// map=[[0,1,1,0,0][1,1,0,1,1][0,0,1,0,0][0,0,1,1,0]]