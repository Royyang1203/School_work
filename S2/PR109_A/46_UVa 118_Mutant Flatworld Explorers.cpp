// UVa 118

// Description

// Robotics, robot motion planning, and machine learning are areas that cross the boundaries of many of the subdisciplines that comprise Computer Science: artificial intelligence, algorithms and complexity,electrical and mechanical engineering to name a few. In addition, robots as “turtles” (inspired bywork by Papert, Abelson, and diSessa) and as “beeper-pickers” (inspired by work by Pattis) have been studied and used by students as an introduction to programming for many years.This problem involves determining the position of a robot exploring a pre-Columbian flat world.Given the dimensions of a rectangular grid and a sequence of robot positions and instructions, you are to write a program that determines for each sequence of robot positions and instructions the final position of the robot.A robot position consists of a grid coordinate (a pair of integers: x-coordinate followed by y coordinate) and an orientation (N,S,E,W for north, south, east, and west). A robot instruction is a string of the letters ‘L’, ‘R’, and ‘F’ which represent, respectively, the instructions:• Left: the robot turns left 90 degrees and remains on the current grid point.• Right: the robot turns right 90 degrees and remains on the current grid point.• Forward: the robot moves forward one grid point in the direction of the current orientation and maintains the same orientation.The direction North corresponds to the direction from grid point (x, y) to grid point (x, y + 1).Since the grid is rectangular and bounded, a robot that moves “off” an edge of the grid is lost forever. However, lost robots leave a robot “scent” that prohibits future robots from dropping off the world at the same grid point. The scent is left at the last grid position the robot occupied before disappearing over the edge. An instruction to move “off” the world from a grid point from which a robot has been previously lost is simply ignored by the current robot.

// Input
// The first line of input is the upper-right coordinates of the rectangular world, the lower-left coordinates are assumed to be 0,0.The remaining input consists of a sequence of robot positions and instructions (two lines per robot).A position consists of two integers specifying the initial coordinates of the robot and an orientation(N,S,E,W), all separated by white space on one line. A robot instruction is a string of the letters ‘L’, ‘R’,and ‘F’ on one line.Each robot is processed sequentially, i.e., finishes executing the robot instructions before the next robot begins execution.Input is terminated by end-of-file.You may assume that all initial robot positions are within the bounds of the specified grid. The maximum value for any coordinate is 50. All instruction strings will be less than 100 characters in length.

// Output
// For each robot position/instruction in the input, the output should indicate the final grid position and orientation of the robot. If a robot falls off the edge of the grid the word ‘LOST’ should be printed after the position and orientation.

// Sample Input 1

// 5 3
// 1 1 E
// RFRFRFRF
// 3 2 N
// FRRFLLFFRRFLL
// 0 3 W
// LLFFFLFLFL
// Sample Output 1

// 1 1 E
// 3 3 N LOST
// 2 3 S

#include <iostream>
#include <vector>
//#define TEST

using namespace std;

class Position
{
public:
    int x;
    int y;
    int d;

    Position(int _x, int _y, int _d) : x(_x), y(_y), d(_d) {}
};

int main()
{
    int _x, _y;
    cin >> _x >> _y;
    int x, y;
    char d;
    int dir;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<Position> v;

    while (cin >> x >> y >> d)
    {
        if (d == 'E')
            dir = 0;
        else if (d == 'N')
            dir = 1;
        else if (d == 'W')
            dir = 2;
        else if (d == 'S')
            dir = 3;
        bool lost = false;
        string s;
        cin >> s;
        for (char c : s)
        {
            bool conti = false;
            if (c == 'F')
            {
                if ((x + dx[dir]) < 0 || (x + dx[dir]) > _x || (y + dy[dir]) < 0 || (y + dy[dir]) > _y)
                {
                    for (Position &p : v)
                        if (p.x == x && p.y == y)
                            conti = true;
                    if (conti)
                        continue;
                    lost = true;
                    v.push_back(Position(x, y, dir));
                    break;
                }
                x += dx[dir];
                y += dy[dir];
#ifdef TEST
                cout << x << " " << y << " ";
                if (dir == 0)
                    cout << 'E';
                else if (dir == 1)
                    cout << 'N';
                else if (dir == 2)
                    cout << 'W';
                else if (dir == 3)
                    cout << 'S';
                cout << endl;
#endif
            }
            else if (c == 'R')
            {
                --dir;
                if (dir == -1)
                    dir = 3;
                dir %= 4;
#ifdef TEST
                cout << x << " " << y << " ";
                if (dir == 0)
                    cout << 'E';
                else if (dir == 1)
                    cout << 'N';
                else if (dir == 2)
                    cout << 'W';
                else if (dir == 3)
                    cout << 'S';
                cout << endl;
#endif
            }
            else if (c == 'L')
            {
                ++dir;
                dir %= 4;
#ifdef TEST
                cout << x << " " << y << " ";
                if (dir == 0)
                    cout << 'E';
                else if (dir == 1)
                    cout << 'N';
                else if (dir == 2)
                    cout << 'W';
                else if (dir == 3)
                    cout << 'S';
                cout << endl;
#endif
            }
        }
        cout << x << " " << y << " ";
        if (dir == 0)
            cout << 'E';
        else if (dir == 1)
            cout << 'N';
        else if (dir == 2)
            cout << 'W';
        else if (dir == 3)
            cout << 'S';
        if (lost)
            cout << " LOST";
        cout << endl;
    }
}