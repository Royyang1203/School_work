#include <iostream>
#include <bits/stdc++.h>

using namespace std;
bool promising(int i);

int n = 4;

int col[10];
bool r[10], c[10], l_diagonal[10], r_diagonal[10];

int cou = -1;

void queens(int i)
{
    int j;
    ++cou;
    if (promising(i))
    {
        // cout << cou << endl;
        // // cout << i << endl;
        // for (int j = 0; j < cou; ++j)
        //     cout << col[j] << " ";
        // cout << endl;
        if (i == n - 1)
        {
            for (int j = 0; j < n; ++j)
                cout << col[j] << " ";
            cout << endl;
        }
        else
            for (int j = 0; j < n; ++j)
            {
                col[i + 1] = j;
                queens(i + 1);
            }
    }
    --cou;
}

bool promising(int i)
{
    int k = 0;
    bool res = true;
    while (k < i && res)
    {
        if (col[i] == col[k] || abs(col[i] - col[k]) == i - k)
            res = false;
        ++k;
    }
    return res;
}

int main()
{
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    memset(l_diagonal, 0, sizeof(l_diagonal));
    memset(r_diagonal, 0, sizeof(r_diagonal));
    queens(-1);
}