#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int qq = 0;

void printBoard(int **board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool isValid(int **board, int row, int col, int z, int n)
{
    for (int i = 0; i < col; i++) // check whether there is queen in the left or not
        if (board[row][i] == z)
            return false;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == z) // check whether there is queen in the left upper diagonal or not
            return false;
    for (int i = row + 1, j = col - 1; j >= 0 && i < n; i++, j--)
        if (board[i][j] == z) // check whether there is queen in the left lower diagonal or not
            return false;
    return true;
}

bool solveNQueen(int **board, int col, int z, int n)
{
    {
        if (col == 0 && z > n)
            return true;
        // if (col == 0)
        // {
        //     ++qq;
        //     // printBoard(board);
        //     // cout << col << z << endl;
        //     if (qq % 1000 == 1)
        //     {
        //         cout << qq << endl;
        //         printBoard(board);
        //         cout << col << z << endl;
        //     }
        //     // int a;
        //     // cin >> a;
        // }

        if (col >= n) // when N queens are placed successfully
        {
            if (z > n)
                return true;
            else
                return solveNQueen(board, 0, z + 1, n);
        }
        for (int i = 0; i < n; i++)
        { // for each row, check placing of queen is possible or not
            if (board[i][col])
                continue;
            if (isValid(board, i, col, z, n))
            {
                board[i][col] = z;                     // if validate, place the queen at place (i, col)
                if (solveNQueen(board, col + 1, z, n)) // Go for the other columns recursively
                    return true;
                board[i][col] = 0; // When no place is vacant remove that queen
            }
        }
        return false; // when no possible order is found
    }

    bool checkSolution(int n)
    {
        int **board = (int **)malloc(n * sizeof(int *));

        int *temp = (int *)malloc(n * n * sizeof(int));
        for (int i = 0; i < n; ++i)
        {
            (board)[i] = (int *)(temp + n * i);
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = 0; // set all elements to 0

        if (solveNQueen(board, 0, 1, n) == false)
        { // starting from 0th column
            cout << "Solution does not exist";
            return false;
        }

        printBoard(board, n);
        return true;
    }
    int main()
    {
        int n;
        cin >> n;
        checkSolution(n);
    }