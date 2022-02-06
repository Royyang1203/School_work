// // #include <iostream>
// // #include <cstdlib>
// // #include <ctime>
// // #include <iomanip>
// // using namespace std;

// // #define SIZE 10
// // #define UP 0
// // #define DOWN 1
// // #define LEFT 2
// // #define RIGHT 3

// // class Grid
// // {
// // public:
// //     Grid() : Grid(0)
// //     {
// //     }
// //     Grid(int s)
// //     {
// //         state = s;
// //         dir[UP] = NULL;
// //         dir[DOWN] = NULL;
// //         dir[LEFT] = NULL;
// //         dir[RIGHT] = NULL;
// //     }
// //     Grid *getDir(int d) const
// //     {
// //         return dir[d];
// //     }
// //     int getState() const
// //     {
// //         return state;
// //     }
// //     void setDir(int d, Grid *g)
// //     {
// //         dir[d] = g;
// //     }
// //     void setState(int s)
// //     {
// //         state = s;
// //     }

// //     friend Grid *trans(Grid *base, int r, int c);

// // private:
// //     Grid *dir[4]; //代表四方向
// //     int state = 1;
// // };

// // class List
// // {
// // public:
// //     List()
// //     {
// //         top = 0;
// //     }
// //     /*
// //     Insert an element from top
// //     */
// //     void addElement(Grid *g)
// //     {
// //         data[top] = g;

// //         top++;
// //     }
// //     /*
// //     remove an element from top and return a pointer point to the element.
// //     If list is empty, return NULL.
// //     */
// //     Grid *removeElement()
// //     {

// //         if (top < 0)
// //         {
// //             return NULL;
// //         }
// //         else
// //         {
// //             Grid *re = data[0];

// //             for (int i = 0; i < top; i++)
// //             {
// //                 data[i] = data[i + 1];
// //             }

// //             top--;
// //             return re;
// //         }
// //     }
// //     void printPath() const
// //     {

// //         int j;
// //         for (j = 1; j < top; j++)
// //         {
// //             if (data[j] == data[j - 1]->getDir(UP))
// //             {
// //                 cout << "UP\n";
// //             }
// //             else if (data[j] == data[j - 1]->getDir(DOWN))
// //             {
// //                 cout << "DOWN\n";
// //             }
// //             else if (data[j] == data[j - 1]->getDir(LEFT))
// //             {
// //                 cout << "LEFT\n";
// //             }
// //             else if (data[j] == data[j - 1]->getDir(RIGHT))
// //             {
// //                 cout << "RIGHT\n";
// //             }
// //         }
// //     }

// // private:
// //     Grid *data[SIZE * SIZE]; //裡面都是指標
// //     int top;
// // };
// // /////////////////////
// // Grid *trans(Grid *base, int r, int c)
// // {
// //     Grid *ret;
// //     ret = base;
// //     for (int i = 0; i <= r; i++)
// //     {
// //         ret = ret->dir[1];
// //     }
// //     for (int i = 0; i <= c; i++)
// //     {
// //         ret = ret->dir[3];
// //     }
// //     return ret;
// // }
// // ///////////////////
// // class Maze
// // {
// // public:
// //     Maze()
// //     {
// //         initMaze(SIZE);
// //     }
// //     /*
// //     function initMaze
// //     Alocate a 2-D link list with s * s sizes as the map of maze.
// //     Inside the maze enery gird with state 0 represent empty space and 1 represent wall.
// //     The gird in left top is start point and right bottom is finish point.
// //     Randomly generate 20% wall in the maze.
// //     Make sure start point and finish point are 0

// //     動態配置一個二維的鏈結串列，大小是 s * s，用這個鏈結串列表示迷宮的地圖
// //     節點中 0 的值表示可以移動的空間， 1 表示牆壁
// //     左上角的位置表示起點，右下角的位置表示終點
// //     請在迷宮中加入 20% 的牆壁
// //     然後確定起點跟終點都是可以移動的位置
// //     */
// //     void initMaze(int s)
// //     {
// //         srand(time(NULL));
// //         //20%可以再見的時候加
// //         int r;
// //         maze = new Grid();
// //         Grid *cur = maze;

// //         for (int i = 0; i < SIZE; i++) //連左右
// //         {
// //             Grid *next = new Grid();
// //             if (i != 0) //連前端
// //             {
// //                 cur->setDir(DOWN, next);
// //                 next->setDir(UP, cur);
// //             }
// //             for (int j = 0; j < SIZE; j++)
// //             {
// //                 Grid *temp = new Grid();
// //                 r = rand() % 4;
// //                 if (r == 0)
// //                 {
// //                     temp->setState(1);
// //                 }
// //                 if (j != 0)
// //                 {
// //                     cur->setDir(3, temp);
// //                     temp->setDir(2, cur);
// //                     cur = temp;
// //                     cout << "   " << (maze->getDir(3))->getState() << "  ";
// //                 }
// //             }
// //             cur = next; //下一行
// //         }

// //         Grid *top;
// //         Grid *low;
// //         for (int r = 0; r < (SIZE - 1); r++) //連上下
// //         {

// //             for (top = trans(maze, r, 0), low = trans(maze, r + 1, 0); top->getDir(3) != NULL; top = top->getDir(3), low = low->getDir(3))
// //             {
// //                 top->setDir(1, low);
// //                 low->setDir(0, top);
// //             }
// //         }
// //     }

// //     /*
// //     function getPath
// //     This function will find a path between start point and finish point.
// //     Return a list content the path information inside.
// //     If there is no path between two point then the list will be empty.

// //     這個函數會找到起點到終點間的一條路徑
// //     回傳一個 list 包含著路徑的資訊
// //     如果找不到路徑的話 list 就會是空的
// //     */
// //     List *getPath()
// //     {
// //         int record[25][20][2] = {0};
// //         int pr, pc;
// //         srand(time(NULL));
// //         record[2][0][0] = 0;
// //         record[2][0][1] = 0;
// //         int count = 2;
// //         int te = 0;
// //         int ini = 1;
// //         ////////////////////////////
// //         while (1)
// //         {
// //             if (trans(maze, 9, 9)->getState() != 0) //結束判斷
// //             {
// //                 break;
// //             }
// //             te = 0;
// //             for (int i = 0; i < 20; i++)
// //             {

// //                 pr = record[count][i][0];
// //                 pc = record[count][i][1];

// //                 if (pr == 0 && pc == 0) //判斷空
// //                 {
// //                     break;
// //                 }

// //                 if (trans(maze, pr + 1, pc)->getState() == 0 && (pr + 1) < SIZE && (pr + 1) >= 0) //下
// //                 {

// //                     trans(maze, pr + 1, pc)->setState(count + 1);

// //                     record[count + 1][te][0] = pr + 1;
// //                     record[count + 1][te][1] = pc;
// //                     te = te + 1;
// //                 }
// //                 if (trans(maze, pr - 1, pc)->getState() == 0 && (pr - 1) < SIZE && (pr - 1) >= 0) //上
// //                 {
// //                     trans(maze, pr - 1, pc)->setState(count + 1);
// //                     record[count + 1][te][0] = pr - 1;
// //                     record[count + 1][te][1] = pc;
// //                     te = te + 1;
// //                 }
// //                 if (trans(maze, pr, pc + 1)->getState() == 0 && (pc + 1) < SIZE && (pc + 1) >= 0) //右
// //                 {
// //                     trans(maze, pr, pc + 1)->setState(count + 1);
// //                     record[count + 1][te][0] = pr;
// //                     record[count + 1][te][1] = pc + 1;
// //                     te = te + 1;
// //                 }

// //                 if (trans(maze, pr, pc - 1)->getState() == 0 && (pc - 1) < SIZE && (pc - 1) >= 0) //左
// //                 {
// //                     trans(maze, pr, pc - 1)->setState(count + 1);
// //                     record[count + 1][te][0] = pr;
// //                     record[count + 1][te][1] = pc - 1;
// //                     te = te + 1;
// //                 }
// //             }
// //             /*
// //                                 for(int i = 0; i<10; i++)
// //                                 {
// //                                     for(int j = 0; j<10; j++)
// //                                     {
// //                                         cout<<setw(2)<<trans(maze2[i],j)->getState()<<' ';
// //                                     }
// //                                     cout<<"\n";
// //                                 }
// //                                 cout<<"\n";

// //             */
// //         }                                       //while end
// //         if (trans(maze, 9, 9)->getState() == 0) //結束判斷
// //         {
// //             return NULL;
// //         }
// //         ////////////////////////find path

// //         Li.addElement(trans(maze, 9, 9));
// //         pr = 9;
// //         pc = 9;

// //         for (int i = count - 1; i > 2;)
// //         {
// //             if (trans(maze, pr + 1, pc)->getState() == i && (pr + 1) < SIZE && (pr + 1) >= 0) //下
// //             {
// //                 Li.addElement(trans(maze, pr + 1, pc));
// //                 i--;
// //                 pr++;

// //                 continue;
// //             }
// //             if (trans(maze, pr - 1, pc)->getState() == i && (pr - 1) < SIZE && (pr - 1) >= 0) //上
// //             {
// //                 Li.addElement(trans(maze, pr - 1, pc));
// //                 i--;
// //                 pr--;

// //                 continue;
// //             }
// //             if (trans(maze, pr, pc + 1)->getState() == i && (pc + 1) < SIZE && (pc + 1) >= 0) //右
// //             {
// //                 Li.addElement(trans(maze, pr, pc + 1));
// //                 i--;
// //                 pc++;

// //                 continue;
// //             }

// //             if (trans(maze, pr, pc - 1)->getState() == i && (pc - 1) < SIZE && (pc - 1) >= 0) //左
// //             {
// //                 Li.addElement(trans(maze, pr, pc - 1));
// //                 i--;
// //                 pc--;

// //                 continue;
// //             }
// //         }

// //         return &Li;
// //     }
// //     void printMaze() const
// //     {
// //         Grid *j = maze, *k;
// //         while (j != NULL)
// //         {
// //             k = j;
// //             while (k != NULL)
// //             {
// //                 cout << k->getState();
// //                 k = k->getDir(RIGHT);
// //             }
// //             cout << endl;
// //             j = j->getDir(DOWN);
// //         }
// //     }

// // private:
// //     Grid *maze;
// //     List Li;
// // };

// // int main()
// // {
// //     Maze *maze = new Maze();
// //     maze->printMaze();
// //     maze->getPath()->printPath();
// // }

// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include <iomanip>
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
//         state++;
//     }
//     Grid(int s)
//     {
//         state = s;
//         dir[UP] = NULL;
//         dir[DOWN] = NULL;
//         dir[LEFT] = NULL;
//         dir[RIGHT] = NULL;
//     }
//     Grid *getDir(int d) const
//     {
//         return dir[d];
//     }
//     int getState() const
//     {
//         return state;
//     }
//     void setDir(int d, Grid *g)
//     {
//         dir[d] = g;
//     }
//     void setState(int s)
//     {
//         state = s;
//     }

//     friend Grid *trans(Grid *base, int r, int c);

// private:
//     Grid *dir[4]; //代表四方向
//     int state = 1;
// };

// class List
// {
// public:
//     List()
//     {
//         top = 0;
//     }
//     /*
//     Insert an element from top
//     */
//     void addElement(Grid *g)
//     {
//         data[top] = g;

//         top++;
//     }
//     /*
//     remove an element from top and return a pointer point to the element.
//     If list is empty, return NULL.
//     */
//     Grid *removeElement()
//     {

//         if (top < 0)
//         {
//             return NULL;
//         }
//         else
//         {
//             Grid *re = data[0];

//             for (int i = 0; i < top; i++)
//             {
//                 data[i] = data[i + 1];
//             }

//             top--;
//             return re;
//         }
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
//     Grid *data[SIZE * SIZE]; //裡面都是指標
//     int top;
// };
// /////////////////////
// Grid *trans(Grid *base, int r, int c)
// {
//     Grid *ret;
//     ret = base;
//     for (int i = 0; i < r; i++)
//     {
//         ret = ret->getDir(1);
//     }
//     for (int i = 0; i < c; i++)
//     {
//         ret = ret->getDir(3);
//     }
//     cout << "fuck" << base->getDir(1);
//     return ret;
// }
// ///////////////////
// class Maze
// {
// public:
//     Maze()
//     {
//         initMaze(SIZE);
//     }
//     /*
//     function initMaze
//     Alocate a 2-D link list with s * s sizes as the map of maze.
//     Inside the maze enery gird with state 0 represent empty space and 1 represent wall.
//     The gird in left top is start point and right bottom is finish point.
//     Randomly generate 20% wall in the maze.
//     Make sure start point and finish point are 0

//     動態配置一個二維的鏈結串列，大小是 s * s，用這個鏈結串列表示迷宮的地圖
//     節點中 0 的值表示可以移動的空間， 1 表示牆壁
//     左上角的位置表示起點，右下角的位置表示終點
//     請在迷宮中加入 20% 的牆壁
//     然後確定起點跟終點都是可以移動的位置
//     */
//     void initMaze(int s)
//     {
//         srand(time(NULL));
//         //20%可以再見的時候加
//         int r;
//         Grid *former = maze2;
//         for (int i = 0; i < SIZE; i++) //連左右
//         {
//             Grid *comp = new Grid;
//             if (i == 0) //連前端
//             {
//                 former->setDir(1, comp);
//                 cout << " comp " << comp;
//                 cout << " co " << former->getDir(1);
//                 comp->setDir(0, former);
//                 cout << "  c " << trans(maze2, 1, 0)->getState();
//             }
//             for (int j = 0; j < SIZE; j++)
//             {

//                 Grid *temp = new Grid;
//                 r = rand() % 5;
//                 if (r == 4)
//                 {
//                     temp->setState(1);
//                 }
//                 if (j != 0)
//                 {
//                     former->setDir(3, temp);

//                     temp->setDir(2, former);
//                     former = temp;
//                     cout << "   " << trans(maze2, i, j)->getState();
//                 }
//             }
//             former = comp; //下一行
//         }

//         Grid *top;
//         Grid *low;
//         for (int r = 0; r < (SIZE - 1); r++) //連上下
//         {

//             for (top = trans(maze2, r, 0), low = trans(maze2, r + 1, 0); top->getDir(3) != NULL; top = top->getDir(3), low = low->getDir(3))
//             {
//                 top->setDir(1, low);
//                 low->setDir(0, top);
//             }
//         }
//         cout << "  flying ";
//     }

//     /*
//     function getPath
//     This function will find a path between start point and finish point.
//     Return a list content the path information inside.
//     If there is no path between two point then the list will be empty.

//     這個函數會找到起點到終點間的一條路徑
//     回傳一個 list 包含著路徑的資訊
//     如果找不到路徑的話 list 就會是空的
//     */
//     List *getPath()
//     {
//         int record[25][20][2] = {0};
//         int pr, pc;
//         srand(time(NULL));
//         record[2][0][0] = 0;
//         record[2][0][1] = 0;
//         int count = 2;
//         int te = 0;
//         int ini = 1;
//         ////////////////////////////
//         while (1)
//         {
//             if (trans(maze2, 9, 9)->getState() != 0) //結束判斷
//             {
//                 break;
//             }
//             te = 0;
//             for (int i = 0; i < 20; i++)
//             {

//                 pr = record[count][i][0];
//                 pc = record[count][i][1];

//                 if (pr == 0 && pc == 0) //判斷空
//                 {
//                     break;
//                 }

//                 if (trans(maze2, pr + 1, pc)->getState() == 0 && (pr + 1) < SIZE && (pr + 1) >= 0) //下
//                 {

//                     trans(maze2, pr + 1, pc)->setState(count + 1);

//                     record[count + 1][te][0] = pr + 1;
//                     record[count + 1][te][1] = pc;
//                     te = te + 1;
//                 }
//                 if (trans(maze2, pr - 1, pc)->getState() == 0 && (pr - 1) < SIZE && (pr - 1) >= 0) //上
//                 {
//                     trans(maze2, pr - 1, pc)->setState(count + 1);
//                     record[count + 1][te][0] = pr - 1;
//                     record[count + 1][te][1] = pc;
//                     te = te + 1;
//                 }
//                 if (trans(maze2, pr, pc + 1)->getState() == 0 && (pc + 1) < SIZE && (pc + 1) >= 0) //右
//                 {
//                     trans(maze2, pr, pc + 1)->setState(count + 1);
//                     record[count + 1][te][0] = pr;
//                     record[count + 1][te][1] = pc + 1;
//                     te = te + 1;
//                 }

//                 if (trans(maze2, pr, pc - 1)->getState() == 0 && (pc - 1) < SIZE && (pc - 1) >= 0) //左
//                 {
//                     trans(maze2, pr, pc - 1)->setState(count + 1);
//                     record[count + 1][te][0] = pr;
//                     record[count + 1][te][1] = pc - 1;
//                     te = te + 1;
//                 }
//             }
//             /*
//                                 for(int i = 0; i<10; i++)
//                                 {
//                                     for(int j = 0; j<10; j++)
//                                     {
//                                         cout<<setw(2)<<trans(maze2[i],j)->getState()<<' ';
//                                     }
//                                     cout<<"\n";
//                                 }
//                                 cout<<"\n";

//             */
//         }                                        //while end
//         if (trans(maze2, 9, 9)->getState() == 0) //結束判斷
//         {
//             return NULL;
//         }
//         ////////////////////////find path

//         Li.addElement(trans(maze2, 9, 9));
//         pr = 9;
//         pc = 9;

//         for (int i = count - 1; i > 2;)
//         {
//             if (trans(maze2, pr + 1, pc)->getState() == i && (pr + 1) < SIZE && (pr + 1) >= 0) //下
//             {
//                 Li.addElement(trans(maze2, pr + 1, pc));
//                 i--;
//                 pr++;

//                 continue;
//             }
//             if (trans(maze2, pr - 1, pc)->getState() == i && (pr - 1) < SIZE && (pr - 1) >= 0) //上
//             {
//                 Li.addElement(trans(maze2, pr - 1, pc));
//                 i--;
//                 pr--;

//                 continue;
//             }
//             if (trans(maze2, pr, pc + 1)->getState() == i && (pc + 1) < SIZE && (pc + 1) >= 0) //右
//             {
//                 Li.addElement(trans(maze2, pr, pc + 1));
//                 i--;
//                 pc++;

//                 continue;
//             }

//             if (trans(maze2, pr, pc - 1)->getState() == i && (pc - 1) < SIZE && (pc - 1) >= 0) //左
//             {
//                 Li.addElement(trans(maze2, pr, pc - 1));
//                 i--;
//                 pc--;

//                 continue;
//             }
//         }

//         return &Li;
//     }
//     void printMaze() const
//     {
//         Grid *j = maze2, *k;
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
//     Grid maze;
//     Grid *maze2 = &maze;

//     List Li;
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
using namespace std;

#define SIZE 10
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
    Grid *getDir(int d) const
    {
        return dir[d];
    }
    int getState() const
    {
        return state;
    }
    void setDir(int d, Grid *g)
    {
        dir[d] = g;
    }
    void setState(int s)
    {
        state = s;
    }

    friend Grid *get_position(Grid *base, int r, int c);

private:
    Grid *dir[4]; //代表四方向
    int state = 1;
};

class List
{
public:
    List()
    {
        top = 0;
    }
    /*
    Insert an element from top
    */
    void addElement(Grid *g)
    {
        data[top] = g;

        top++;
    }
    /*
    remove an element from top and return a pointer point to the element.
    If list is empty, return NULL.
    */
    Grid *removeElement()
    {

        if (top < 0)
        {
            return NULL;
        }
        else
        {
            Grid *re = data[0];

            for (int i = 0; i < top; i++)
            {
                data[i] = data[i + 1];
            }

            top--;
            return re;
        }
    }
    void printPath() const //
    {
        cout << '\n';

        int j;
        for (j = 0; j < top; j++)
        {
            cout << j << "   " << data[j]->getState();
            cout << '\n';
            if (data[j] == data[j - 1]->getDir(UP))
            {
                cout << '\n'
                     << " j " << j;
                cout << "UP\n";
            }
            else if (data[j] == data[j - 1]->getDir(DOWN))
            {
                cout << '\n'
                     << " j " << j;
                cout << "DOWN\n";
            }
            else if (data[j] == data[j - 1]->getDir(LEFT))
            {
                cout << '\n'
                     << " j " << j;
                cout << "LEFT\n";
            }
            else if (data[j] == data[j - 1]->getDir(RIGHT))
            {
                cout << '\n'
                     << " j " << j;
                cout << "RIGHT\n";
            }
        }
    }

private:
    Grid *data[SIZE * SIZE]; //裡面都是指標
    int top;
};
/////////////////////

///////////////////
class Maze
{
public:
    Maze()
    {
        initMaze(SIZE);
    }
    /*
    function initMaze
    Alocate a 2-D link list with s * s sizes as the map of maze.
    Inside the maze enery gird with state 0 represent empty space and 1 represent wall.
    The gird in left top is start point and right bottom is finish point.
    Randomly generate 20% wall in the maze.
    Make sure start point and finish point are 0

    動態配置一個二維的鏈結串列，大小是 s * s，用這個鏈結串列表示迷宮的地圖
    節點中 0 的值表示可以移動的空間， 1 表示牆壁
    左上角的位置表示起點，右下角的位置表示終點
    請在迷宮中加入 20% 的牆壁
    然後確定起點跟終點都是可以移動的位置
    */
    void initMaze(int s)
    {
        maze2 = new Grid();

        srand(time(NULL));
        //20%可以再見的時候加
        int r;
        Grid *former = maze2;
        for (int i = 0; i < SIZE; i++) //連左右
        {
            if (i != 0) //連前端
            {
                Grid *first = new Grid();
                this->get_position(i - 1, 0)->setDir(DOWN, first);
                first->setDir(UP, get_position(i - 1, 0));
            }
            for (int j = 1; j < SIZE; j++)
            {
                Grid *temp = new Grid();
                /* r = rand()%5;*/
                if (r == 0)
                {
                    temp->setState(1);
                }
                this->get_position(i, j - 1)->setDir(RIGHT, temp);
                temp->setDir(LEFT, get_position(i, j - 1));
            }
        }

        for (int r = 0; r < (SIZE - 1); r++) //連上下,友聯好
        {
            for (int c = 1; c < SIZE; ++c)
            {
                this->get_position(r, c)->setDir(DOWN, this->get_position(r + 1, c));
                this->get_position(r + 1, c)->setDir(UP, this->get_position(r, c));
            }
        }
    }

    /*
    function getPath
    This function will find a path between start point and finish point.
    Return a list content the path information inside.
    If there is no path between two point then the list will be empty.

    這個函數會找到起點到終點間的一條路徑
    回傳一個 list 包含著路徑的資訊
    如果找不到路徑的話 list 就會是空的
    */
    // ini一進其他城市就無法往上了
    // List *getPath()
    // {

    //     maze2->setState(2);
    //     get_position(maze2, 9, 9)->setState(0);

    //     int record[25][20][2] = {0};
    //     int pr, pc;
    //     srand(time(NULL));
    //     record[2][0][0] = 0;
    //     record[2][0][1] = 0;
    //     int count = 2;
    //     int te = 0;
    //     int ini = 1;

    //     ////////////////////////////
    //     while (1)
    //     {
    //         if (get_position(maze2, 9, 9)->getState() != 0) //結束判斷
    //         {
    //             cout << "break";
    //             break;
    //         }
    //         te = 0;

    //         for (int i = 0; i < 20; i++)
    //         {

    //             pr = record[count][i][0];
    //             pc = record[count][i][1];

    //             if (!(count == 2 && i == 0) && pr == 0 && pc == 0) //判斷空
    //             {
    //                 break;
    //             }
    //             cout << "count  " << count;
    //             if ((pr + 1) < SIZE && (pr + 1) >= 0 && get_position(maze2, pr + 1, pc)->getState() == 0) //下
    //             {
    //                 cout << "down";

    //                 get_position(maze2, pr + 1, pc)->setState(count + 1);

    //                 record[count + 1][te][0] = pr + 1;
    //                 record[count + 1][te][1] = pc;
    //                 te = te + 1;
    //             }
    //             if ((pr - 1) < SIZE && (pr - 1) >= 0 && get_position(maze2, pr - 1, pc)->getState() == 0 && (pr - 1) < SIZE && (pr - 1) >= 0) //上
    //             {
    //                 cout << "up";
    //                 get_position(maze2, pr - 1, pc)->setState(count + 1);
    //                 record[count + 1][te][0] = pr - 1;
    //                 record[count + 1][te][1] = pc;
    //                 te = te + 1;
    //             }
    //             if ((pc + 1) < SIZE && (pc + 1) >= 0 && get_position(maze2, pr, pc + 1)->getState() == 0) //右
    //             {
    //                 cout << "right";
    //                 get_position(maze2, pr, pc + 1)->setState(count + 1);
    //                 record[count + 1][te][0] = pr;
    //                 record[count + 1][te][1] = pc + 1;
    //                 te = te + 1;
    //             }

    //             if ((pc - 1) < SIZE && (pc - 1) >= 0 && get_position(maze2, pr, pc - 1)->getState() == 0 && (pc - 1) < SIZE && (pc - 1) >= 0) //左
    //             {
    //                 cout << "left";
    //                 get_position(maze2, pr, pc - 1)->setState(count + 1);
    //                 record[count + 1][te][0] = pr;
    //                 record[count + 1][te][1] = pc - 1;
    //                 te = te + 1;
    //             }
    //         }
    //         count++;
    //         cout << '\n';
    //         this->printMaze();
    //     }                                               //while end
    //     if (get_position(maze2, 0, 0)->getState() == 0) //結束判斷
    //     {
    //         return NULL;
    //     }
    //     ////////////////////////find path
    //     //7 50

    //     Li.addElement(get_position(maze2, 9, 9));
    //     pr = 9;
    //     pc = 9;

    //     for (int i = count - 1; i >= 2;)
    //     {
    //         if ((pr + 1) < SIZE && (pr + 1) >= 0 && get_position(maze2, pr + 1, pc)->getState() == i) //下
    //         {
    //             cout << " pr   pc   do" << pr << "   " << pc << "    " << get_position(maze2, pr, pc)->getState();
    //             cout << '\n';
    //             Li.addElement(get_position(maze2, pr + 1, pc));
    //             i--;
    //             pr++;

    //             continue;
    //         }
    //         if ((pr - 1) < SIZE && (pr - 1) >= 0 && get_position(maze2, pr - 1, pc)->getState() == i) //上
    //         {
    //             cout << " pr   pc   up" << pr << "   " << pc << "    " << get_position(maze2, pr, pc)->getState();
    //             cout << '\n';
    //             Li.addElement(get_position(maze2, pr - 1, pc));
    //             i--;
    //             pr--;

    //             continue;
    //         }
    //         if ((pc + 1) < SIZE && (pc + 1) >= 0 && get_position(maze2, pr, pc + 1)->getState() == i) //右
    //         {
    //             cout << " pr   pc   ri" << pr << "   " << pc << "    " << get_position(maze2, pr, pc)->getState();
    //             cout << '\n';
    //             Li.addElement(get_position(maze2, pr, pc + 1));
    //             i--;
    //             pc++;

    //             continue;
    //         }

    //         if ((pc - 1) < SIZE && (pc - 1) >= 0 && get_position(maze2, pr, pc - 1)->getState() == i) //左
    //         {
    //             Li.addElement(get_position(maze2, pr, pc - 1));
    //             i--;
    //             pc--;
    //             cout << " pr   pc   le" << pr << "   " << pc << "    " << get_position(maze2, pr, pc)->getState();
    //             cout << '\n';
    //             continue;
    //         }
    //     }
    //     cout << "   show time   ";

    //     return &Li;
    // }
    void printMaze() const
    {
        Grid *j = this->get_position(9, 9), *k;
        while (j != NULL)
        {
            k = j;
            while (k != NULL)
            {
                cout << setw(2) << k->getState(); //已更改setw
                k = k->getDir(LEFT);
            }
            cout << endl;
            j = j->getDir(UP);
        }
    }

private:
    // Grid maze;
    Grid *maze2;
    List Li;

    Grid *get_position(const int r, const int c) const
    {
        Grid *cur = maze2;
        for (int i = 0; i < r; i++)
        {
            cur = cur->getDir(DOWN);
        }
        for (int i = 0; i < c; i++)
        {
            cur = cur->getDir(RIGHT);
        }
        return cur;
    }
};

int main()
{
    Maze *maze = new Maze();

    maze->printMaze();
    // maze->getPath()->printPath();
}