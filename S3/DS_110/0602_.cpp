// Description

// 請完成樣板中的類別以及成員函數。

// Please finish the class and member function in template.

// 這題的期限到2021/11/12

// This assignment due to 2021/11/12

// #include <iostream>
// #include <cstdlib>
// #include <ctime>

// using namespace std;

// #define SIZE 10
// #define UP 0
// #define DOWN 1
// #define LEFT 2
// #define RIGHT 3

// class Grid
// {
// public:
//     Grid() : Grid(0)
//     {
//     }
//     Grid(int s)
//     {
//         state = s;
//         dir[UP] = NULL;
//         dir[DOWN] = NULL;
//         dir[LEFT] = NULL;
//         dir[RIGHT] = NULL;
//     }
//     Grid *getDir(int d) const { return dir[d]; }
//     int getState() const { return state; }
//     void setDir(int d, Grid *g) { dir[d] = g; }
//     void setState(int s) { state = s; }

// private:
//     Grid *dir[4];
//     int state;
// };

// class List
// {
// public:
//     List()
//     {
//         top = 0;
//     }
//     /*
// 	Insert an element from top
// 	*/
//     void addElement(Grid *g)
//     {
//     }
//     /*
// 	remove an element from top and return a pointer point to the element.
// 	If list is empty, return NULL.
// 	*/
//     Grid *removeElement()
//     {
//     }
//     void printPath() const
//     {
//         int j;
//         for (j = 1; j < top; j++)
//         {
//             if (data[j] == data[j - 1]->getDir(UP))
//             {
//                 cout << "UP\n";
//             }
//             else if (data[j] == data[j - 1]->getDir(DOWN))
//             {
//                 cout << "DOWN\n";
//             }
//             else if (data[j] == data[j - 1]->getDir(LEFT))
//             {
//                 cout << "LEFT\n";
//             }
//             else if (data[j] == data[j - 1]->getDir(RIGHT))
//             {
//                 cout << "RIGHT\n";
//             }
//         }
//     }

// private:
//     Grid *data[SIZE * SIZE];
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
// 	Alocate a 2-D link list with s * s sizes as the map of maze.
// 	Inside the maze enery gird with state 0 represent empty space and 1 represent wall.
// 	The gird in left top is start point and right bottom is finish point.
// 	Randomly generate 20% wall in the maze.
// 	Make sure start point and finish point are 0

// 	動態配置一個二維的鏈結串列，大小是 s * s，用這個鏈結串列表示迷宮的地圖
// 	節點中 0 的值表示可以移動的空間， 1 表示牆壁
// 	左上角的位置表示起點，右下角的位置表示終點
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
// 	回傳一個 list 包含著路徑的資訊
// 	如果找不到路徑的話 list 就會是空的
// 	*/
//     List *getPath()
//     {
//     }
//     void printMaze() const
//     {
//         Grid *j = maze, *k;
//         while (j != NULL)
//         {
//             k = j;
//             while (k != NULL)
//             {
//                 cout << k->getState();
//                 k = k->getDir(RIGHT);
//             }
//             cout << endl;
//             j = j->getDir(DOWN);
//         }
//     }

// private:
//     Grid *maze;
// };

// int main()
// {
//     Maze *maze = new Maze();
//     maze->printMaze();
//     maze->getPath()->printPath();
// }

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <deque>

using namespace std;

#define SIZE 100
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

class Grid
{
public:
    Grid() : Grid(0)
    {
    }
    Grid(int s)
    {
        state = s;
        dir[UP] = NULL;
        dir[DOWN] = NULL;
        dir[LEFT] = NULL;
        dir[RIGHT] = NULL;
    }

    /**
     * get the dir up, down, left or right from current Grid
     */
    Grid *getDir(int d) const
    {
        return dir[d];
    }

    /**
     * get the state of this Grid
     */
    int getState() const
    {
        return state;
    }
    /**
     * set the dir of this Grid
     */
    void setDir(int d, Grid *g)
    {
        dir[d] = g;
    }

    /**
     * set the state of this Grid
     */
    void setState(int s)
    {
        state = s;
    }

    /**
     * @brief return the position that down for _r rows and right for _c columns from current grid
     * @return Grid pointer
     * @param _r rows that go down
     * @param _c columns that go right
     */
    Grid *get_position(int _r, int _c)
    {
        Grid *res = this;
        for (int i = 0; i < _r; ++i)
            res = res->getDir(DOWN);
        for (int j = 0; j < _c; ++j)
            res = res->getDir(RIGHT);
        return res;
    }

private:
    Grid *dir[4]; // the pointer(0) up(1), down(2), left(3) or right from current
    int state;    // 障礙物(-1), 未算距離(0), 牆(1), 距離(3+)
};

class List
{
public:
    List()
    {
        top = 0;
    }

    /**
     * Insert an element into List
	 */
    bool addElement(Grid *_g)
    {
        if (top >= SIZE * SIZE)
            return false;
        data[top++] = _g;
        return true;
    }
    bool addElement(Grid *_g, int _n)
    {
        if (_n >= SIZE * SIZE)
            return false;
        data[_n] = _g;
        return true;
    }
    bool set_top(int _n)
    {
        top = _n;
        cout << top << endl;
        return true;
    }

    /**
     * remove an element from top and return a pointer point to the element.
     * If list is empty, return NULL.
	 */
    Grid *removeElement()
    {
        if (top <= 0)
            return nullptr;
        return data[--top];
    }

    void printPath() const
    {
        if (top == 0)
            cout << "No path to end" << endl;
        int j;
        for (j = 1; j < top; j++)
        {
            if (data[j] == data[j - 1]->getDir(UP))
            {
                cout << "UP\n";
            }
            else if (data[j] == data[j - 1]->getDir(DOWN))
            {
                cout << "DOWN\n";
            }
            else if (data[j] == data[j - 1]->getDir(LEFT))
            {
                cout << "LEFT\n";
            }
            else if (data[j] == data[j - 1]->getDir(RIGHT))
            {
                cout << "RIGHT\n";
            }
        }
    }

private:
    Grid *data[SIZE * SIZE];
    int top;
};

class Maze
{
public:
    Maze()
    {
        initMaze(SIZE);
    }

    /**
     * @brief initial a  s * s maze and generate some wall.
     * @param _s the side lengh of the maze.
     * @return void.\n
     *
     * Alocate a 2-D link list with s * s sizes as the map of maze.\n
     * Inside the maze enery gird with state 0 represent empty space and 1 represent wall.\n
     * The gird in left top is start point and right bottom is finish point.
     * Randomly generate 20% wall in the maze.
     * Make sure start point and finish point are 0.
     * 動態配置一個二維的鏈結串列，大小是 s * s，用這個鏈結串列表示迷宮的地圖
     * 節點中 0 的值表示可以移動的空間， 1 表示牆壁
     * 左上角的位置表示起點，右下角的位置表示終點
     * 請在迷宮中加入 20% 的牆壁
     * 然後確定起點跟終點都是可以移動的位置
     *
	 */
    void initMaze(int _s)
    {
        Grid ***ptr = new Grid **[_s];
        Grid **temp = new Grid *[_s * _s];

        for (int i = 0; i < _s; ++i)
            ptr[i] = temp + i * _s;

        // new Grid
        for (int i = 0; i < _s; ++i)
        {
            for (int j = 0; j < _s; ++j)
                ptr[i][j] = new Grid();
        }

        // bind pointer
        for (int i = 0; i < _s - 1; ++i)
        {
            for (int j = 0; j < _s; ++j)
            {
                ptr[i][j]->setDir(DOWN, ptr[i + 1][j]);
                ptr[_s - i - 1][j]->setDir(UP, ptr[_s - i - 2][j]);
                ptr[j][i]->setDir(RIGHT, ptr[j][i + 1]);
                ptr[j][_s - i - 1]->setDir(LEFT, ptr[j][_s - i - 2]);
            }
        }

        // generate wall
        srand(time(nullptr));
        for (int i = 0; i < _s * _s * 0.2;)
        {
            int r = rand() % _s;
            int c = rand() % _s;
            if (ptr[r][c]->getState() == 0 && !(r == 0 && c == 0) && !(r == _s - 1 && c == _s - 1))
            {
                ptr[r][c]->setState(1);
                ++i;
            }
        }

        maze = ptr[0][0];
        delete[] temp;
        delete[] ptr;
    }

    /**
     * This function will find a path between start point and finish point.
     * Return a list content the path information inside.
     * If there is no path between two point then the list will be empty.
     * 這個函數會找到起點到終點間的一條路徑
     * 回傳一個 list 包含著路徑的資訊
     * 如果找不到路徑的話 list 就會是空的
	 */
    List *getPath()
    {
        // 找最短步數
        deque<Grid *> q;

        // 設定起點
        maze->get_position(0, 0)->setState(3);
        q.push_back(maze->get_position(0, 0));

        // 廣度優先走訪，算距離
        while (!q.empty())
        {
            Grid *cur = q.front();

            for (int i = 0; i < 4; ++i)
            {
                Grid *next = cur->getDir(i);

                // 未設定距離，或是有更短距離者才可以設定新距離，並將該節點加入走訪序列
                if (next && (next->getState() == 0 || next->getState() > cur->getState() + 1))
                {
                    next->setState(cur->getState() + 1);
                    q.push_back(next);
                }
            }
            q.pop_front();
        }

        this->printMaze();

        List *res = new List();

        Grid *cur = maze->get_position(SIZE - 1, SIZE - 1);

        // 是否無解
        if (cur->getState() == 0)
            return res;

        // 編路徑
        make_path(maze, res);

        res->printPath();

        // 編路徑，由終點往起點
        // res->set_top(cur->getState() - 2);
        // res->addElement(cur, cur->getState() - 3);
        // cout << "dddd" << endl;
        // res->printPath();
        // cout << "dddd" << endl;

        // while (cur->getState() != maze->getState())
        // {
        //     // cout << cur;
        //     for (int i = 0; i < 4; ++i)
        //     {
        //         if (cur && cur->getDir(i)->getState() == cur->getState() - 1)
        //         {
        //             // res->printPath();
        //             // cout << "iiii" << endl;
        //             cur = cur->getDir(i);
        //             // cout << "#" << cur->getState() - 3 << "EE" << cur << endl;

        //             res->addElement(cur, cur->getState() - 3);
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
    int make_path(Grid *cur, List *res)
    {
        res->addElement(cur);

        // 到達終點
        if (cur == maze->get_position(SIZE - 1, SIZE - 1))
        {
            return 1;
        }

        // 往四個方向遞迴，但只會往距離更大的遞迴
        for (int i = 0; i < 4; ++i)
        {
            Grid *next = cur->getDir(i);
            if (next && next->getState() == cur->getState() + 1)
            {
                if (make_path(next, res))
                    return true;
            }
        }

        // 死路，刪除，才不會重別處遞迴到一樣的路
        cur->setState(-1);
        res->removeElement();
        return false;
    }

    void printMaze() const
    {
        for (int i = 0; i < SIZE + 2; ++i)
        {
            if ((i == 0 || i == SIZE + 1))
                cout << setw(3) << "  ";
            else
                cout << setw(3) << i - 1;
        }
        cout << endl;
        Grid *j = maze, *k;
        int i = -1;
        while (j != NULL)
        {
            k = j;
            cout << setw(3) << ++i;
            while (k != NULL)
            {
                int cur = k->getState();
                if (cur == 1)
                    cout << setw(3) << "*";
                else if (cur == -1)
                    cout << setw(3) << "x";
                else if (cur == 0)
                    cout << setw(3) << " ";
                else
                    cout << setw(3) << cur;
                k = k->getDir(RIGHT);
            }
            cout << setw(3) << i;
            cout << endl;
            j = j->getDir(DOWN);
            cout << endl;
        }
        for (int i = 0; i < SIZE + 2; ++i)
        {
            if ((i == 0 || i == SIZE + 1))
                cout << setw(3) << "  ";
            else
                cout << setw(3) << i - 1;
        }
        cout << endl;
    }

private:
    Grid *maze;
};

int main()
{
    Maze *maze = new Maze();
    maze->printMaze();
    cout << endl;
    maze->getPath()->printPath();
    maze->printMaze();
}
