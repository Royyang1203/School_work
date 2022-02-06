// 請完成樣板中的類別以及成員函數。

// Please finish the class and member function in template.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

struct Grid
{
    struct Grid *dir[4];
    int state;
};

struct List
{
    struct Grid *data[SIZE * SIZE];
    int top;
};

/*
Insert an element from top
*/
void addElement(List *l, Grid *g)
{
}

/*
remove an element from top and return a pointer point to the element.
If list is empty, return NULL.
*/
Grid *removeElement(List *l)
{
}

/*
function initMaze
Alocate a 2-D link list with s * s sizes as the map of maze.
Inside the maze enery gird with state 0 represent empty space and 1 represent wall.
The gird in left top is start point and right bottom is finish point.
Randomly generate 20% wall in the maze.
Make sure start point and finish point are 0

動態配置一個二維的鏈結串列，大小是 s*s ，用這個鏈結串列表示迷宮的地圖
節點中 0 的值表示可以移動的空間， 1 表示牆壁
左上角的位置表示起點，右下角的位置表示終點
請在迷宮中加入 20% 的牆壁
然後確定起點跟終點都是可以移動的位置
*/
void initMaze(Grid **m, int s)
{
}

/*
function findPath
This function will find a path between start point and finish point.
Return a list content the path information inside.
If there is no path between two point then the list will be empty.

這個函數會找到起點到終點間的一條路徑
回傳一個 list 包含著路徑的資訊
如果找不到路徑的話 list 就會是空的
*/
List *findPath(Grid *m)
{
    return NULL;
}

void printPath(List *l)
{
    int j;
    for (j = 1; j < l->top; j++)
    {
        if (l->data[j] == l->data[j - 1]->dir[UP])
        {
            printf("UP\n");
        }
        else if (l->data[j] == l->data[j - 1]->dir[DOWN])
        {
            printf("DOWN\n");
        }
        else if (l->data[j] == l->data[j - 1]->dir[LEFT])
        {
            printf("LEFT\n");
        }
        else if (l->data[j] == l->data[j - 1]->dir[RIGHT])
        {
            printf("RIGHT\n");
        }
    }
}

void printMaze(Grid *m)
{
    Grid *j = m, *k;
    while (j != NULL)
    {
        k = j;
        while (k != NULL)
        {
            printf("%d ", k->state);
            k = k->dir[RIGHT];
        }
        printf("\n");
        j = j->dir[DOWN];
    }
}

int main()
{
    Grid *maze = NULL;
    initMaze(&maze, SIZE);
    printMaze(maze);
    printPath(findPath(maze));
    return 0;
}
