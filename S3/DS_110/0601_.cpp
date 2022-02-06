// Description

// 請完成樣板中的類別以及成員函數。

// Please finish the class and member function in template.

// #include <iostream>
// #include <cstdlib>
// #include <ctime>

// #define SIZE 10

// using namespace std;

// class Node
// {
// public:
//     Node() : Node(0, 0)
//     {
//     }
//     Node(int r, int c)
//     {
//         row = r;
//         col = c;
//     }
//     int getRow() const { return row; }
//     int getCol() const { return col; }
//     void setRow(int r)
//     {
//         if (r >= 0 && r < SIZE)
//             row = r;
//     }
//     void setCol(int c)
//     {
//         if (c >= 0 && c < SIZE)
//             col = c;
//     }

// private:
//     int col, row, data;
// };

// class List
// {
// public:
//     List()
//     {
//         top = 0;
//     }
//     /*
// 	function addElement
// 	Insert an element into list
// 	*/
//     void addElement(int r, int c)
//     {
//     }
//     /*
// 	function removeElement
// 	remove an element from list and return a pointer point to the element.
// 	If list is empty, return NULL.
// 	*/
//     Node *removeElement()
//     {
//     }
//     void printList()
//     {
//         int j;
//         for (j = 0; j < top; j++)
//         {
//             cout << "(" << data[j].getRow() << ", " << data[j].getCol() << ")" << endl;
//         }
//     }

// private:
//     Node data[SIZE * SIZE];
//     int top;
// };

// class Maze
// {
// public:
//     Maze()
//     {
//         initMaze(SIZE);
//     }
//     /*
// 	function initMaze
// 	Alocate a 2-D array with s * s sizes as the map of maze.
// 	Inside the maze where 0 represent empty space and 1 represent wall.
// 	[0][0] is start point and [s - 1][s - 1] is finish point.
// 	Randomly generate 20% wall in the maze.
// 	Make sure [0][0] and [s - 1][s - 1] are 0

// 	動態配置一個二維的陣列，大小是 s * s ，用這個陣列表示迷宮的地圖
// 	陣列中 0 的值表示可以移動的空間， 1 表示牆壁
// 	[0][0] 的位置表示起點 [s - 1][s - 1] 的位置表示終點
// 	請在迷宮中加入 20% 的牆壁
// 	然後確定起點跟終點都是可以移動的位置
// 	*/
//     void initMaze(int s)
//     {
//     }
//     /*
// 	function getPath
// 	This function will find a path between start point and finish point.
// 	Return a list content the path information inside.
// 	If there is no path between two point then the list will be empty.

// 	這個函數會找到起點到終點間的一條路徑
// 	回傳一個 list， List 包含路徑的資訊
// 	如果找不到路徑的話 list 就會是空的
// 	*/
//     List *getPath()
//     {
//     }
//     void printMaze()
//     {
//         int j, k;
//         int **temp[10];
//         temp = &maze for (j = 0; j < SIZE; j++)
//         {
//             for (k = 0; k < SIZE; k++)
//             {
//                 if (maze[j][k] == 0)
//                     cout << " ";
//                 else if (maze[j][k] == 1)
//                     cout << "*";
//             }
//             cout << "\n";
//         }
//     }

// private:
//     int **maze;
// };

// int main()
// {
//     Maze *maze = new Maze();
//     maze->printMaze();
//     maze->getPath()->printList();
// }

// 這題的期限到2021/11/12

// This assignment due to 2021/11/12

// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include <iomanip>

// #define SIZE 10

// using namespace std;

// class Node
// {
// public:
//     Node() = default;
//     Node(int r, int c) : row(r), col(c) {}
//     int getRow() const
//     {
//         return row;
//     }
//     int getCol() const
//     {
//         return col;
//     }
//     Node *setRow(int r)
//     {
//         if (r >= 0 && r < SIZE)
//             row = r;
//         return this;
//     }
//     Node *setCol(int c)
//     {
//         if (c >= 0 && c < SIZE)
//             col = c;
//         return this;
//     }

// private:
//     int col = 0, row = 0, data = 0;
// };

// class List
// {
// public:
//     List() = default;

//     bool addElement(int r, int c)
//     {
//         // Insert an element into list
//         if (top >= SIZE * SIZE)
//             return false;
//         data[top++].setRow(r)->setCol(c);
//         return true;
//     }
//     Node *removeElement()
//     {
//         // remove an element from list and return a pointer point to the element.
//         // If list is empty, return NULL.
//         if (top <= 0)
//             return nullptr;
//         return &data[--top];
//     }
//     void printList()
//     {
//         int j;
//         for (j = 0; j < top; j++)
//         {
//             cout << "(" << data[j].getRow() << ", " << data[j].getCol() << ")" << endl;
//         }
//     }

// private:
//     Node data[SIZE * SIZE];
//     int top = 0;
// };

// class Maze
// {
// public:
//     Maze()
//     {
//         initMaze(SIZE);
//     }

//     void initMaze(int s)
//     {
//         // Alocate a 2-D array with s * s sizes as the map of maze.
//         // Inside the maze where 0 represent empty space and 1 represent wall.
//         // [0][0] is start point and [s - 1][s - 1] is finish point.
//         // Randomly generate 20% wall in the maze.
//         // Make sure [0][0] and [s - 1][s - 1] are 0
//         // 動態配置一個二維的陣列，大小是 s * s ，用這個陣列表示迷宮的地圖
//         // 陣列中 0 的值表示可以移動的空間， 1 表示牆壁
//         // [0][0] 的位置表示起點 [s - 1][s - 1] 的位置表示終點
//         // 請在迷宮中加入 20% 的牆壁
//         // 然後確定起點跟終點都是可以移動的位置

//         // alocate array
//         maze = (int **)malloc(s * sizeof(int *));

//         int *temp = (int *)malloc(s * s * sizeof(int));
//         for (int i = 0; i < s; ++i)
//         {
//             maze[i] = (int *)(temp + s * i);
//         }

//         // clear data
//         for (int i = 0; i < s; ++i)
//         {
//             for (int j = 0; j < s; ++j)
//             {
//                 maze[i][j] = 0;
//             }
//         }
//         // generate wall
//         srand(time(nullptr));
//         for (int i = 0; i < 20;)
//         {
//             int x = rand() % 10;
//             int y = rand() % 10;
//             if (maze[x][y] == 0 && !(x == 0 && y == 0) && !(x == s - 1 && y == s - 1))
//             {
//                 maze[x][y] = 1;
//                 ++i;
//             }
//         }
//     }

//     List *getPath()
//     {
//         // This function will find a path between start point and finish point.
//         // Return a list content the path information inside.
//         // If there is no path between two point then the list will be empty.
//         // 這個函數會找到起點到終點間的一條路徑
//         // 回傳一個 list， List 包含路徑的資訊d
//         // 如果找不到路徑的話 list 就會是空的
//         List *res = new List();
//         find_next(0, 0, res, 3);
//         return res;
//     }
//     bool find_next(const int _r, const int _c, List *res, int _num)
//     {
//         // -1 means we find the path
//         // 0  means we don't find it yet
//         // potitive integer means need to go back @back steps
//         static const int pos_x[4] = {1, 0, -1, 0};
//         static const int pos_y[4] = {0, 1, 0, -1};
//         static int back = 0;

//         this->printMaze();
//         cout << _r << " " << _c << " ## " << endl;
//         if (_num % 5 == 0)
//         {
//             cout << endl;
//             char c;
//             scanf("%c", &c);
//         }

//         if (back > 0)
//         {
//             --back;
//             return 0;
//         }

//         if (maze[_r][_c] > 3)
//         {
//             back = _num - maze[_r][_c];
//             return 0;
//         }
//         else if (_r >= SIZE || _c >= SIZE || _r < 0 || _c < 0 || maze[_r][_c] != 0)
//             return 0;
//         // add current position to the List
//         res->addElement(_r, _c);
//         // mark current position so that we won't get into a loop
//         maze[_r][_c] = _num;
//         if (_r == SIZE - 1 && _c == SIZE - 1)
//             return 1;
//         for (int i = 0; i < 4; ++i)
//         {
//             if (find_next(_r + pos_y[i], _c + pos_x[i], res, _num + 1))
//                 return 1;
//         }

//         // erase the mark
//         maze[_r][_c] = 0;
//         // delete the position
//         res->removeElement();
//         return 0;
//     }
//     void printMaze()
//     {
//         for (int i = 0; i < SIZE + 2; ++i)
//         {
//             for (int j = 0; j < SIZE + 2; ++j)
//             {
//                 // cout << i << " " << j << endl;
//                 if ((j == 0 || j == SIZE + 1) && (i == 0 || i == SIZE + 1))
//                     cout << setw(2) << "  ";
//                 else if (j == 0 || j == SIZE + 1)
//                     cout << setw(2) << i - 1;
//                 else if (i == 0 || i == SIZE + 1)
//                     cout << setw(2) << j - 1;
//                 else if (maze[i - 1][j - 1] == 1)
//                     cout << " *";
//                 else if (maze[i - 1][j - 1] == 0)
//                     cout << "  ";
//                 else
//                     cout << setw(2) << maze[i - 1][j - 1];
//             }
//             cout << endl;
//         }
//     }

// private:
//     int **maze;
// };

// int main()
// {
//     Maze *maze = new Maze();
//     maze->printMaze();
//     char s;
//     scanf("%c", &s);
//     maze->getPath();
//     // maze->getPath()->printList();
//     cout << endl;
//     maze->printMaze();
// }

// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include <iomanip>

// #define SIZE 10

// using namespace std;

// class Node
// {
// public:
//     Node() = default;
//     Node(int r, int c) : row(r), col(c) {}
//     int getRow() const
//     {
//         return row;
//     }
//     int getCol() const
//     {
//         return col;
//     }
//     Node *setRow(int r)
//     {
//         if (r >= 0 && r < SIZE)
//             row = r;
//         return this;
//     }
//     Node *setCol(int c)
//     {
//         if (c >= 0 && c < SIZE)
//             col = c;
//         return this;
//     }

// private:
//     int col = 0, row = 0, data = 0;
// };

// class List
// {
// public:
//     List() = default;

//     bool addElement(int r, int c)
//     {
//         // Insert an element into list
//         if (top >= SIZE * SIZE)
//             return false;
//         data[top++].setRow(r)->setCol(c);
//         return true;
//     }
//     Node *removeElement()
//     {
//         // remove an element from list and return a pointer point to the element.
//         // If list is empty, return NULL.
//         if (top <= 0)
//             return nullptr;
//         return &data[--top];
//     }
//     void printList()
//     {
//         int j;
//         for (j = 0; j < top; j++)
//         {
//             cout << "(" << data[j].getRow() << ", " << data[j].getCol() << ")" << endl;
//         }
//     }

// private:
//     Node data[SIZE * SIZE];
//     int top = 0;
// };

// class Maze
// {
// public:
//     Maze()
//     {
//         initMaze(SIZE);
//     }

//     void initMaze(int s)
//     {
//         // Alocate a 2-D array with s * s sizes as the map of maze.
//         // Inside the maze where 0 represent empty space and 1 represent wall.
//         // [0][0] is start point and [s - 1][s - 1] is finish point.
//         // Randomly generate 20% wall in the maze.
//         // Make sure [0][0] and [s - 1][s - 1] are 0
//         // 動態配置一個二維的陣列，大小是 s * s ，用這個陣列表示迷宮的地圖
//         // 陣列中 0 的值表示可以移動的空間， 1 表示牆壁
//         // [0][0] 的位置表示起點 [s - 1][s - 1] 的位置表示終點
//         // 請在迷宮中加入 20% 的牆壁
//         // 然後確定起點跟終點都是可以移動的位置

//         // alocate array
//         maze = (int **)malloc(s * sizeof(int *));

//         int *temp = (int *)malloc(s * s * sizeof(int));
//         for (int i = 0; i < s; ++i)
//         {
//             maze[i] = (int *)(temp + s * i);
//         }

//         // clear data
//         for (int i = 0; i < s; ++i)
//         {
//             for (int j = 0; j < s; ++j)
//             {
//                 maze[i][j] = 0;
//             }
//         }
//         // generate wall
//         srand(time(nullptr));
//         for (int i = 0; i < 20;)
//         {
//             int x = rand() % 10;
//             int y = rand() % 10;
//             if (maze[x][y] == 0 && !(x == 0 && y == 0) && !(x == s - 1 && y == s - 1))
//             {
//                 maze[x][y] = 1;
//                 ++i;
//             }
//         }
//     }

//     List *getPath()
//     {
//         // This function will find a path between start point and finish point.
//         // Return a list content the path information inside.
//         // If there is no path between two point then the list will be empty.
//         // 這個函數會找到起點到終點間的一條路徑
//         // 回傳一個 list， List 包含路徑的資訊d
//         // 如果找不到路徑的話 list 就會是空的
//         List *res = new List();
//         find_next(0, 0, res, 3);
//         return res;
//     }
//     bool find_next(const int _r, const int _c, List *res, int _num)
//     {
//         static const int dir_x[4] = {0, 1, 0, -1};
//         static const int dir_y[4] = {-1, 0, 1, 0};
//         static int pos = 0; // 現在貼哪道牆 0 上 1 右 2 下

//         this->printMaze();
//         cout << _r << " " << _c << " ## " << pos << endl;
//         if (_num % 5 == 0)
//         {
//             cout << endl;
//             char c;
//             scanf("%c", &c);
//         }

//         if (_r >= SIZE || _c >= SIZE || _r < 0 || _c < 0 || maze[_r][_c] != 0)
//             return 0;
//         // add current position to the List
//         res->addElement(_r, _c);
//         // mark current position so that we won't get into a loop
//         maze[_r][_c] = _num;
//         if (_r == SIZE - 1 && _c == SIZE - 1)
//             return 1;
//         for (int i = 0; i < 4; ++i)
//         {
//             int rr = _r + dir_y[(i + pos) % 4];
//             int cc = _c + dir_x[(i + pos) % 4];

//             if (i == 3 && maze[_r + dir_y[(i + pos) % 4]][_c + dir_x[(i + pos) % 4]] == 0 && pos == 0)
//             {
//                 ++pos;
//             }

//             if (find_next(rr, cc, res, _num + 1))
//                 return 1;
//         }

//         // erase the mark
//         maze[_r][_c] = 0;
//         // delete the position
//         res->removeElement();
//         return 0;
//     }
//     void printMaze()
//     {
//         for (int i = 0; i < SIZE + 2; ++i)
//         {
//             for (int j = 0; j < SIZE + 2; ++j)
//             {
//                 // cout << i << " " << j << endl;
//                 if ((j == 0 || j == SIZE + 1) && (i == 0 || i == SIZE + 1))
//                     cout << setw(2) << "  ";
//                 else if (j == 0 || j == SIZE + 1)
//                     cout << setw(2) << i - 1;
//                 else if (i == 0 || i == SIZE + 1)
//                     cout << setw(2) << j - 1;
//                 else if (maze[i - 1][j - 1] == 1)
//                     cout << " *";
//                 else if (maze[i - 1][j - 1] == 0)
//                     cout << "  ";
//                 else
//                     cout << setw(2) << maze[i - 1][j - 1];
//             }
//             cout << endl;
//         }
//     }

// private:
//     int **maze;
// };

// int main()
// {
//     Maze *maze = new Maze();
//     maze->printMaze();
//     char s;
//     scanf("%c", &s);
//     maze->getPath();
//     // maze->getPath()->printList();
//     cout << endl;
//     maze->printMaze();
// }

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <deque>

#define SIZE 10

using namespace std;

class Node
{
public:
    Node() = default;
    Node(int r, int c) : row(r), col(c) {}
    int getRow() const
    {
        return row;
    }
    int getCol() const
    {
        return col;
    }
    Node *setRow(int r)
    {
        if (r >= 0 && r < SIZE)
            row = r;
        return this;
    }
    Node *setCol(int c)
    {
        if (c >= 0 && c < SIZE)
            col = c;
        return this;
    }

private:
    int col = 0, row = 0, data = 0;
};

class List
{
public:
    List() = default;

    /**
     * Insert an element into list
     */
    bool addElement(int r, int c)
    {
        if (top >= SIZE * SIZE)
            return false;
        data[top++].setRow(r)->setCol(c);
        return true;
    }
    bool addElement(int r, int c, int _n)
    {
        if (_n >= SIZE * SIZE)
            return false;
        data[_n].setRow(r)->setCol(c);
        return true;
    }
    bool set_top(int _n)
    {
        top = _n;
        // cout << top << endl;
        return true;
    }

    /**
     * remove an element from list and return a pointer point to the element.
     * If list is empty, return NULL.
     */
    Node *removeElement()
    {
        if (top <= 0)
            return nullptr;
        return &data[--top];
    }

    void printList()
    {
        if (top == 0)
            cout << "No path to end" << endl;
        int j;
        for (j = 0; j < top; j++)
        {
            cout << "(" << data[j].getRow() << ", " << data[j].getCol() << ")" << endl;
        }
    }

private:
    Node data[SIZE * SIZE];
    int top = 0;
};

class Maze
{
public:
    Maze()
    {
        initMaze(SIZE);
    }

    /**
     * Alocate a 2-D array with s * s sizes as the map of maze.
     * Inside the maze where 0 represent empty space and 1 represent wall.
     * [0][0] is start point and [s - 1][s - 1] is finish point.
     * Randomly generate 20% wall in the maze.
     * Make sure [0][0] and [s - 1][s - 1] are 0
     * 動態配置一個二維的陣列，大小是 s * s ，用這個陣列表示迷宮的地圖
     * 陣列中 0 的值表示可以移動的空間， 1 表示牆壁
     * [0][0] 的位置表示起點 [s - 1][s - 1] 的位置表示終點
     * 請在迷宮中加入 20% 的牆壁
     * 然後確定起點跟終點都是可以移動的位置
     */
    void initMaze(int s)
    {
        // alocate array
        maze = (int **)malloc(s * sizeof(int *));
        int *temp = (int *)malloc(s * s * sizeof(int));

        for (int i = 0; i < s; ++i)
        {
            maze[i] = (temp + s * i);
        }

        // clear data
        for (int i = 0; i < s; ++i)
        {
            for (int j = 0; j < s; ++j)
            {
                maze[i][j] = 0;
            }
        }

        // generate wall
        srand(time(nullptr));
        for (int i = 0; i < 20;)
        {
            int x = rand() % 10;
            int y = rand() % 10;
            if (maze[x][y] == 0 && !(x == 0 && y == 0) && !(x == s - 1 && y == s - 1))
            {
                maze[x][y] = 1;
                ++i;
            }
        }
    }

    /**
     * This function will find a path between start point and finish point.
     * Return a list content the path information inside.
     * If there is no path between two point then the list will be empty.
     * 這個函數會找到起點到終點間的一條路徑
     * 回傳一個 list， List 包含路徑的資訊d
     * 如果找不到路徑的話 list 就會是空的
     */
    List *getPath()
    {
        const int dir_x[4] = {0, 1, 0, -1};
        const int dir_y[4] = {-1, 0, 1, 0};

        // 找最短步數
        deque<Node> q;
        maze[0][0] = 3;
        q.push_back(Node(0, 0));
        while (!q.empty())
        {
            Node cur = q.front();
            int y = cur.getRow();
            int x = cur.getCol();
            // cout << y << "##" << x << endl;
            for (int i = 0; i < 4; ++i)
            {
                int next_x = x + dir_x[i];
                int next_y = y + dir_y[i];
                // cout << cur_y << ", " << cur_x << endl;
                if (next_x < 0 || next_y < 0 || next_x >= 10 || next_y >= 10)
                    continue;
                if (maze[next_x][next_y] == 0 || maze[next_x][next_y] > maze[x][y] + 1)
                {
                    // cout << " if " << endl;
                    maze[next_x][next_y] = maze[x][y] + 1;
                    q.push_back(Node(next_y, next_x));
                }
            }
            q.pop_front();
        }

        this->printMaze();

        List *res = new List();
        if (maze[SIZE - 1][SIZE - 1] == 0)
            return res;

        // 編路徑
        make_path(0, 0, res);
        // 編路徑，由終點往起點
        // res->set_top(SIZE - 1, SIZE - 1, maze[SIZE - 1][SIZE - 1] - 2);
        // res->addElement(SIZE - 1, SIZE - 1, maze[SIZE - 1][SIZE - 1] - 3);

        // while (cur->getState() != maze->getState())
        // {
        //     // cout << cur;
        //     for (int i = 0; i < 4; ++i)
        //     {
        //         if (cur && cur->getDir(i)->getState() == cur->getState() - 1)
        //         {
        //             cur = cur->getDir(i);
        //             cout << cur->getState() - 2 << endl;

        //             res->addElement(cur, cur->getState() - 2);
        //             break;
        //         }
        //     }
        // }

        return res;
    }

    /**
     * 遞迴函式
     * 深度優先搜尋路徑
     * 下一步的距離必定為現在的距離 +1
     * 遇到死路會標記
     */
    int make_path(int _x, int _y, List *res)
    {
        static const int dir_x[4] = {0, 1, 0, -1};
        static const int dir_y[4] = {-1, 0, 1, 0};

        res->addElement(_x, _y);

        if (maze[_x][_y] == maze[SIZE - 1][SIZE - 1])
        {
            return 1;
        }
        for (int i = 0; i < 4; ++i)
        {
            int cur_x = _x + dir_x[i];
            int cur_y = _y + dir_y[i];
            // cout << cur_y << ", " << cur_x << endl;
            if (cur_x < 0 || cur_y < 0 || cur_x >= 10 || cur_y >= 10)
                continue;
            if (maze[cur_x][cur_y] == maze[_x][_y] + 1)
            {
                // cout << " if " << endl;
                if (make_path(cur_x, cur_y, res))
                    return true;
            }
        }

        // 死路，刪除，才不會重別處遞迴到一樣的路
        maze[_x][_y] = -1;
        res->removeElement();
        return false;
    }

    /**
     * 四周會印出編號，每個 cell 分三格空間
     * "*" 代表牆壁
     * 數字代表最短距離
     * "x" 代表死路
     * 空格代表還未計算最短距離
     */
    void printMaze()
    {
        for (int i = 0; i < SIZE + 2; ++i)
        {
            for (int j = 0; j < SIZE + 2; ++j)
            {
                if ((j == 0 || j == SIZE + 1) && (i == 0 || i == SIZE + 1))
                    cout << setw(3) << "  ";
                else if (j == 0 || j == SIZE + 1)
                    cout << setw(3) << i - 1;
                else if (i == 0 || i == SIZE + 1)
                    cout << setw(3) << j - 1;
                else if (maze[i - 1][j - 1] == 1)
                    cout << setw(3) << "*";
                else if (maze[i - 1][j - 1] == -1)
                    cout << setw(3) << "x";
                else if (maze[i - 1][j - 1] == 0)
                    cout << setw(3) << " ";
                else
                    cout << setw(3) << maze[i - 1][j - 1];
            }
            cout << endl;
        }
    }

private:
    int **maze;
};

int main()
{
    Maze *maze = new Maze();
    maze->printMaze();
    cout << endl;
    // char s;
    // scanf("%c", &s);
    // maze->getPath();
    maze->getPath()->printList();
    // cout << endl;
    maze->printMaze();
}