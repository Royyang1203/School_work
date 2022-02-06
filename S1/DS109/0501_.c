// 請完成樣板中的類別以及成員函數。

//     Please finish the class and member function in template.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

struct Node
{
    int row, col;
};

struct List
{
    struct Node data[SIZE * SIZE];
    int top;
};

/*
Insert an element from list
*/
void addElement(List *l, int r, int c)
{
}

/*
remove an element from list and return a pointer point to the element.
If list is empty, return NULL.
*/
Node *removeElement(List *l)
{
}

/*
function initMaze
Alocate a 2-D array with s * s sizes as the map of maze.
Inside the maze where 0 represent empty space and 1 represent wall.
[0][0] is start point and [s - 1][s - 1] is finish point.
Randomly generate 20% wall in the maze.
Make sure [0][0] and [s - 1][s - 1] are 0

動態配置一個二維的陣列，大小是 s*s ，用這個陣列表示迷宮的地圖
陣列中 0 的值表示可以移動的空間， 1 表示牆壁
[0][0] 的位置表示起點 [s - 1][s - 1] 的位置表示終點
請在迷宮中加入 20% 的牆壁
然後確定起點跟終點都是可以移動的位置
*/
void initMaze(int ***m, int s)
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
List *findPath(int **m, int s)
{
    return NULL;
}

void printPath(List *l)
{
    if (l == NULL)
        return;
    int j;
    for (j = 0; j < l->top; j++)
    {
        printf("(%d, %d) ", l->data[j].row, l->data[j].col);
    }
}

void printMaze(int *m[SIZE])
{
    int j, k;
    for (j = 0; j < SIZE; j++)
    {
        for (k = 0; k < SIZE; k++)
        {
            if (m[j][k] == 0)
                printf(" ");
            else if (m[j][k] == 1)
                printf("*");
        }
        printf("\n");
    }
}

int main()
{
    int **maze;
    initMaze(&maze, SIZE);
    printMaze(maze);
    printPath(findPath(maze, SIZE));
    return 0;
}
