// UVa 10189

// Description

// Have you ever played Minesweeper? It’s a cute little game which comes within a certain Operating System which name we can’t really remember.
// Well, the goal of the game is to find where are all the mines within a M × N field. To help you,
// the game shows a number in a square which tells you how many mines there are adjacent to that square.
// For instance, supose the following 4 × 4 field with 2 mines (which are represented by an ‘*’ character):

// *...

// ....

// .*..

// ....

// If we would represent the same field placing the hint numbers described above, we would end up with:

// *100

// 2210

// 1*10

// 1110

// As you may have already noticed, each square may have at most 8 adjacent squares.

// Input
// The input will consist of an arbitrary number of fields. The first line of each field
// contains two integers n and m (0 < n, m ≤ 100) which stands for the number of lines
// and columns of the field respectively. The next n lines contains exactly m characters and represent the field.

// Each safe square is represented by an ‘.’ character (without the quotes)
// and each mine square is represented by an ‘*’ character (also without the quotes).
// The first field line where n = m = 0 represents the end of input and should not be processed.

// Output
// For each field, you must print the following message in a line alone:

// Field #x:

// Where x stands for the number of the field (starting from 1).
// The next n lines should contain the field with the ‘.’ characters replaced
// by the number of adjacent mines to that square. There must be an empty line between field outputs.

// Sample Input 1

// 4 4
// *...
// ....
// .*..
// ....
// 3 5
// **...
// .....
// .*...
// 0 0
// Sample Output 1

// Field #1:
// *100
// 2210
// 1*10
// 1110

// Field #2:
// **100
// 33200
// 1*100

#include <iostream>
#include <string>

using namespace std;
int main()
{
    int n, m, t = 0;
    while (cin >> n >> m)
    {
        if (n == 0 || m == 0)
            return 0;
        char maze[n][m];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> maze[i][j];
            }
        }
        cout << "Field #" << ++t << ":" << endl;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (maze[i][j] == '*')
                    cout << '*';
                else
                {
                    int k = 0;
                    if (maze[i - 1][j] == '*' && i - 1 >= 0 && i - 1 < n)
                        ++k;
                    if (maze[i + 1][j] == '*' && i + 1 >= 0 && i + 1 < n)
                        ++k;
                    if (maze[i][j - 1] == '*' && j - 1 >= 0 && j - 1 < m)
                        ++k;
                    if (maze[i][j + 1] == '*' && j + 1 >= 0 && j + 1 < m)
                        ++k;
                    if (maze[i - 1][j - 1] == '*' && i - 1 >= 0 && i - 1 < n && j - 1 >= 0 && j - 1 < m)
                        ++k;
                    if (maze[i - 1][j + 1] == '*' && i - 1 >= 0 && i - 1 < n && j + 1 >= 0 && j + 1 < m)
                        ++k;
                    if (maze[i + 1][j - 1] == '*' && i + 1 >= 0 && i + 1 < n && j - 1 >= 0 && j - 1 < m)
                        ++k;
                    if (maze[i + 1][j + 1] == '*' && i + 1 >= 0 && i + 1 < n && j + 1 >= 0 && j + 1 < m)
                        ++k;
                    cout << k;
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}