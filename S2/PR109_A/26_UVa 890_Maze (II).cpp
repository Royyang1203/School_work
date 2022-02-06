// UVa 890

// Johnny like solving puzzles. He especially likes drawing and solving mazes. However, solving a maze he has drawn himself is too easy for him.

// Since his computer is his best friend, he figures that he needs a program drawing the mazes for him. So he starts thinking about an algorithm performing this difficult task for him and he comes up with "Johnny's Simple Algorithm."

// Johnny's Simple Algorithm
// You start with a M \times NM×N grid, where MM is the number of rows and NN is the number of columns of the grid. Initially, no two cells of the grid are connected to each other, so every cell is surrounded by walls on all four sides. The walls consist of an underscore ('_') for a horizontal wall, and a vertical bar ('|') for a vertical one. For example, if M = 3M=3 and N = 4N=4, the grid looks like this:

//  _ _ _ _
// |_|_|_|_|
// |_|_|_|_|
// |_|_|_|_|
// Every cell of the grid has unique coordinates (p, q)(p,q). The lower left corner in the example is (1, 1)(1,1), the upper right corner is (3, 4)(3,4).

// After choosing the dimensions of the maze, you choose a starting cell. From now on you keep track of a list of pending cells, which initially contains only one cell (the starting cell), and you repeat the following steps'

// If the list is empty, you stop The maze is ready.
// Else, you consider the most recently added cell in the list (call this cell ACAC). If this cell (at the end of the list) has no~ unvisited~ neighbor cells then you remove this cell from the list. Every cell has at most 44 neighbor cells: on the right, left, above, and below. A cell is unvisited if it has never been added to the list.
// If ACAC has at least one unvisited neighbor cell, you choose one of the unvisited neighbor cells (call this cell NCNC), remove the wall between ACAC and NCNC and add NCNC to the end of the list.
// Johnny makes a nice little program using this algorithm and it works fine, but Johnny is not completely satisfied with the results. He is a demanding little boy and in his opinion the so-called branching factor of the maze is too low, i.e. the generated mazes contain very long paths and too few crossings. Therefore, the mazes are still too easy to solve for him.

// A little trick can be applied to Johnny's Simple Algorithm, giving much better results. Johnny does not know it, but you will, since it will be explained below!

// The idea behind the trick is to sometimes change the order of the cells in the list. This avoids long paths and result in more branches. Changing the order of the cells in the list is done by 'flipping' part of the list. A flip can be specified by giving the position of a cell in the list (where the first cell has position 1) and consists of reversing the sub-list starting at the specified cell and ending with the last cell in the list.

// For example, if the list consists of the following cells:

// (1, 1)(1, 2)(2, 2)(3, 2)(3, 3)(1,1)(1,2)(2,2)(3,2)(3,3)
// then a flip with starting cell number 2 results in:

// (1, 1)(3, 3)(3, 2)(2, 2)(1, 2)(1,1)(3,3)(3,2)(2,2)(1,2)
// Now, we will reveal "Johnny's Advanced Algorithm."

// Johnny's Advanced Algorithm
// The algorithm is pretty much the same as "Johnny's Simple Algorithm", only sometimes part of the list is flipped. The steps you repeat after choosing the dimensions of the maze, choosing the starting cell and adding this cell to the list are:

// If the list of cells is empty, you stop. The maze is ready.
// Else you consider the last cell in the list. If this cell has no unvisited neighbor cells, then you remove this cell from the list.
// Otherwise, you read a command. If this command is:
// 'F nn' you flip the list, starting at position nn.
// 'U' you go up: you remove the wall between the last cell in the list and the cell above it. The cell above the last cell in the list is added to the list.
// 'D' you go down.
// 'L' you go left.
// 'R' you go right.
// Since you are taking part in a programming lab, we ask you to write a program generating nice mazes for Johnny, using "Johnny's Advanced Algorithm", to make him happy again. The maximum size of a maze is 39 \times 3939×39.

// Input
// The first line of the input contains the number of test cases. The input for every test case is divided into tree parts:

// The first line contains two integer values MM and NN, specifying the dimensions of the maze: the number of rows MM followed by the number of column NN.
// The second line contains the coordinates of the starting point (again, row followed by column).
// The next lines each contain a command. A command is one of the upper case character 'F', 'U', 'D', 'L', and 'R', appearing at the start of a line. An 'F' character is followed by a space and an integer (the staring position of the flip.)
// The input for each test case contains exactly the number of commands needed for the maze.

// Output
// The resulting mazes should be printed using spaces ('~ '), underscores ('_'), vertical bars ('|') and end-of-line characters. No unnecessary whitespace should be printed. The mazes should be followed by one blank line.

// Sample Input 1

// 2
// 3 3
// 1 1
// U
// U
// R
// D
// D
// R
// U
// U
// 3 4
// 2 1
// R
// U
// L
// F 2
// R
// U
// R
// D
// D
// F 4
// D
// L
// L
// Sample Output 1

//  _ _ _
// |   | |
// | | | |
// |_|_ _|

//  _ _ _ _
// |_  |   |
// |_ _  | |
// |_ _ _|_|

#include <iostream>

class Point2D
{
private:
public:
    int c = 0, r = 0;

    Point2D() = default;
    Point2D &operator=(const Point2D &that)
    {
        this->r = that.r;
        this->c = that.c;
        return *this;
    }
};

using namespace std;

void flip(Point2D *ptr, int first, int n)
{
    for (int i = 0; i < n / 2; ++i)
    {
        int t = ptr[i + first].c;
        ptr[i + first].c = ptr[n - i - 1].c;
        ptr[n - i - 1].c = t;
        t = ptr[i + first].r;
        ptr[i + first].r = ptr[n - i - 1].r;
        ptr[n - i - 1].r = t;
    }
}

int main()
{
    int testcase, n, m, r, c;
    char maze[41][82];
    cin >> testcase;
    while (testcase--)
    {
        cin >> n >> m;
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= 2 * m; ++j)
            {
                if (j % 2)
                    maze[i][j] = '_';
                else if (i == 0)
                    maze[i][j] = ' ';
                else
                    maze[i][j] = '|';
            }
        }
        Point2D pointSet[n * m + 2];
        int cells = 0;
        bool visited[n][m];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                visited[i][j] = false;
        cin >> r >> c;
        r = n - r;
        --c;
        pointSet[cells].c = c;
        pointSet[cells++].r = r;
        visited[r][c] = true;
        //

        //
        while (cells)
        {
            for (; cells; --cells)
            {
                Point2D &cell = pointSet[cells - 1];
                if (cell.r - 1 >= 0 && cell.r - 1 < n && cell.c >= 0 && cell.c < m && !visited[cell.r - 1][cell.c] ||
                    cell.r + 1 >= 0 && cell.r + 1 < n && cell.c >= 0 && cell.c < m && !visited[cell.r + 1][cell.c] ||
                    cell.r >= 0 && cell.r < n && cell.c + 1 >= 0 && cell.c + 1 < m && !visited[cell.r][cell.c + 1] ||
                    cell.r >= 0 && cell.r < n && cell.c - 1 >= 0 && cell.c - 1 < m && !visited[cell.r][cell.c - 1])
                    break;
                //cout << cells << "cells" << endl;
            }
            if (cells == 0)
                break;
            Point2D &cell = pointSet[cells - 1];
            char cmd[5];
            cin >> cmd;

            switch (cmd[0])
            {
            case 'F':
                int n;
                cin >> n;
                if (n < cells)
                    flip(pointSet, n - 1, cells);
                break;
            case 'U':
                r = cell.r - 1;
                c = cell.c;
                maze[r + 1][c * 2 + 1] = ' ';
                pointSet[cells].c = c;
                pointSet[cells].r = r;
                ++cells;
                visited[r][c] = true;
                break;
            case 'D':
                r = cell.r + 1;
                c = cell.c;
                maze[r][c * 2 + 1] = ' ';
                pointSet[cells].c = c;
                pointSet[cells].r = r;
                ++cells;
                visited[r][c] = true;
                break;
            case 'L':
                r = cell.r;
                c = cell.c - 1;
                maze[r + 1][(c + 1) * 2] = ' ';
                pointSet[cells].c = c;
                pointSet[cells].r = r;
                ++cells;
                visited[r][c] = true;
                break;
            case 'R':
                r = cell.r;
                c = cell.c + 1;
                maze[r + 1][c * 2] = ' ';
                pointSet[cells].c = c;
                pointSet[cells].r = r;
                ++cells;
                visited[r][c] = true;
                break;
            }
            /*
            for (int i = 0; i <= n; ++ i)
            {
                for (int j = 0; j <= 2 * m; ++ j)
                {
                    if (i == 0 && j == 2 * m)
                        continue;
                    else
                        cout << maze[i][j];
                }
                cout << endl;
            }
            */
        }
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= 2 * m; ++j)
            {
                if (i == 0 && j == 2 * m)
                    continue;
                else
                    cout << maze[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
}

// _____________________________________________________________

// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>

// //#define TT

// class Cell
// {
// public:
//     int r = 0;
//     int c = 0;
//     Cell() = default;
//     Cell(int _r, int _c) : r(_r), c(_c) {}
// };

// using namespace std;

// int main()
// {

//     int testcase = 0;
//     cin >> testcase;
//     while (testcase--)
//     {
//         int n, m;
//         cin >> n >> m;
//         bool visited[n][m] = {0};
//         for (int i = 0; i < n; ++i)
//             for (int j = 0; j < m; ++j)
//                 visited[i][j] = false;
//         char maze[n + 1][2 * m + 1];
//         for (int i = 0; i < n + 1; ++i)
//         {
//             for (int j = 0; j < 2 * m + 1; ++j)
//             {
//                 if (j % 2)
//                     maze[i][j] = '_';
//                 else if (i == 0)
//                     maze[i][j] = ' ';
//                 else
//                     maze[i][j] = '|';
//             }
//         }
//         vector<Cell> v;
//         int r, c;
//         cin >> r >> c;
//         r = n - r;
//         c = c - 1;
//         v.push_back(Cell(r, c));
//         visited[r][c] = true;
//         while (!v.empty())
//         {
//             while (!v.empty())
//             {
//                 int rr = v.back().r;
//                 int cc = v.back().c;
//                 if (rr + 1 >= 0 && rr + 1 < n && cc >= 0 && cc < m && !visited[rr + 1][cc] ||
//                     rr - 1 >= 0 && rr - 1 < n && cc >= 0 && cc < m && !visited[rr - 1][cc] ||
//                     rr >= 0 && rr < n && cc + 1 >= 0 && cc + 1 < m && !visited[rr][cc + 1] ||
//                     rr >= 0 && rr < n && cc - 1 >= 0 && cc - 1 < m && !visited[rr][cc - 1])
//                     break;
//                 v.pop_back();
//             }
//             if (v.empty())
//                 break;
//             char cmd;
//             cin >> cmd;
//             r = v.back().r;
//             c = v.back().c;
//             switch (cmd)
//             {
//             case 'F':
//                 int n;
//                 cin >> n;
//                 reverse(v.begin() + n - 1, v.end());
//                 break;
//             case 'U':
//                 r -= 1;
//                 v.push_back(Cell(r, c));
//                 visited[r][c] = true;
//                 maze[r + 1][c * 2 + 1] = ' ';
//                 break;
//             case 'D':
//                 r += 1;
//                 v.push_back(Cell(r, c));
//                 visited[r][c] = true;
//                 maze[r][c * 2 + 1] = ' ';
//                 break;
//             case 'R':
//                 c += 1;
//                 v.push_back(Cell(r, c));
//                 visited[r][c] = true;
//                 maze[r + 1][c * 2] = ' ';
//                 break;
//             case 'L':
//                 c -= 1;
//                 v.push_back(Cell(r, c));
//                 visited[r][c] = true;
//                 maze[r + 1][c * 2 + 2] = ' ';
//                 break;
//             }
// #ifdef TT
//             for (int i = 0; i < n + 1; ++i)
//             {
//                 for (int j = 0; j < 2 * m + 1; ++j)
//                 {
//                     if (i == 0 && j == 2 * m)
//                         continue;
//                     cout << maze[i][j];
//                 }
//                 cout << endl;
//             }
// #endif // TT
//         }
//         for (int i = 0; i < n + 1; ++i)
//         {
//             for (int j = 0; j < 2 * m + 1; ++j)
//             {
//                 if (i == 0 && j == 2 * m)
//                     continue;
//                 cout << maze[i][j];
//             }
//             cout << endl;
//         }
//         cout << endl;
//     }

//     return 0;
// }
