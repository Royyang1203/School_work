// UVa 989

// Description

// In many newspapers we may find some puzzles to solve, one of those is Su Doku. Given a grid 9 × 9 with some of entries filled, the objective is to fill in the grid so that every row, every column, and every 3 × 3 box contains the digits 1 through 9.

// image.png

// Input
// Input contains several test cases separated by a blank line. Each of them contains an integer n such that 1 ≤ n ≤ 3 and a grid n^2 × n^2 with some of the entries filled with digits from 1 to n^2 (an entries not filled will have 0). In this case, the objective is to fill in the grid so that every row, every column, and every n × n box contains the digits 1 through n^2.

// Output
// A solution for the problem. If exists more than one, you should give the lower one assuming a lexicographic order. If there is no solution, you should print ‘NO SOLUTION’. For lexicographic comparison you should consider lines in first place. Print a blank line between test cases.

// Sample Input 1

// 3
// 0 6 0 1 0 4 0 5 0
// 0 0 8 3 0 5 6 0 0
// 2 0 0 0 0 0 0 0 1
// 8 0 0 4 0 7 0 0 6
// 0 0 6 0 0 0 3 0 0
// 7 0 0 9 0 1 0 0 4
// 5 0 0 0 0 0 0 0 2
// 0 0 7 2 0 6 9 0 0
// 0 4 0 5 0 8 0 7 0
// Sample Output 1

// 9 6 3 1 7 4 2 5 8
// 1 7 8 3 2 5 6 4 9
// 2 5 4 6 8 9 7 3 1
// 8 2 1 4 3 7 5 9 6
// 4 9 6 8 5 2 3 1 7
// 7 3 5 9 6 1 8 2 4
// 5 8 9 7 1 3 4 6 2
// 3 1 7 2 4 6 9 8 5
// 6 4 2 5 9 8 1 7 3

#include <iostream>

using namespace std;
int board[9][9];
int n, m;

bool put_number(int r, int c)
{
    if (r >= m) // 填完最後一個數字
        return true;

    if (board[r][c] == 0)
    {
        bool col[10] = {false};
        bool row[10] = {false};
        bool box[10] = {false};

        //b找出該欄與該列已經填過哪些數字
        for (int i = 0; i < m; ++i)
        {
            if (board[r][i]) // 如果不為零，這個數字就不能填了
                row[board[r][i]] = true;
            if (board[i][c])
                col[board[i][c]] = true;
        }

        // 找出所在位置的九宮格裡已經填過哪些數字
        int rr = r - (r % n);
        int cc = c - (c % n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (board[rr + i][cc + j])
                    box[board[rr + i][cc + j]] = true;

        // 確認1~9哪些數字能填在這格,如果能填則繼續遞迴
        for (int num = 1; num <= m; ++num)
        {
            if (!col[num] && !row[num] && !box[num]) // 確認這個數字是否可以填
            {
                board[r][c] = num;

                int nxt_r = r, nxt_c = c + 1;
                if (nxt_c == m) //換行
                {
                    ++nxt_r;
                    nxt_c = 0;
                }
                if (put_number(nxt_r, nxt_c)) // 往下一個數字遞迴
                    return true;

                board[r][c] = 0; // 將遞迴做的假設擦掉
            }
        }
    }
    else // board[r][c] != 0
    {
        int nxt_r = r, nxt_c = c + 1;
        if (nxt_c == m) //換行
        {
            ++nxt_r;
            nxt_c = 0;
        }
        if (put_number(nxt_r, nxt_c))
            return true;
    }
    return false;
}

int main()
{
    int t = 0;
    while (cin >> n)
    {
        if (t++)
            cout << endl;
        m = n * n;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < m; ++j)
                cin >> board[i][j];
        }
        if (put_number(0, 0))
        {
            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (j)
                        cout << " ";
                    cout << board[i][j];
                }
                cout << endl;
            }
        }
        else
            cout << "NO SOLUTION" << endl;
    }
}