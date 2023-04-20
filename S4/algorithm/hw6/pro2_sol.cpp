#include <iostream>
#include <bits/stdc++.h>
#define N 100
using namespace std;
bool promising(int i);

int n = 6;

int col[N];
bool r[N], c[N], l_diagonal[2 * N], r_diagonal[2 * N];

int row = 0;

void queens(int i)
{
    int j;
    ++row;
    if (promising(i))
    {
        // cout << row << endl;
        // // cout << i << endl;
        // for (int j = 1; j < row; ++j)
        //     cout << col[j] << " ";
        // cout << endl;
        if (i == n)
        {
            for (int j = 1; j <= n; ++j)
                cout << col[j] << " ";
            cout << endl;
        }
        else
            for (int j = 1; j <= n; ++j)
            {
                col[i + 1] = j;
                queens(i + 1);
            }
        r[i] = true;
        c[i] = true;
        r_diagonal[i - row + n] = true;
        l_diagonal[i - row + n] = true;
    }
    --row;
}

bool promising(int i)
{
    int k = 1;
    bool res = true;
    while (k < i && res)
    {
        if (col[i] == col[k] || abs(col[i] - col[k]) == i - k)
            res = false;
        ++k;
    }
    // if (r[i] || c[i] || r_diagonal[i] || l_diagonal[i])
    //     res = false;
    // if (res)
    // {
    //     cout << "pro" << i << endl;
    //     r[i] = true;
    //     c[i] = true;
    //     r_diagonal[i - row + n] = true;
    //     l_diagonal[i - row + n] = true;
    // }

    return res;
}

int main()
{
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    memset(l_diagonal, 0, sizeof(l_diagonal));
    memset(r_diagonal, 0, sizeof(r_diagonal));
    queens(0);
}