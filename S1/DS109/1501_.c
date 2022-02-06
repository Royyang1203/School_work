// adjacency matrix 是表示一種圖結構的常用表示方法。它用數矩陣陣記錄各點之間是否有邊相連

// 上面的圖轉換 adjacency matrix 後的結果為

// [[1, 1, 0, 0, 1, 0],
//  [1, 0, 1, 0, 1, 0],
//  [0, 1, 0, 1, 0, 0],
//  [0, 0, 1, 0, 1, 1],
//  [1, 1, 0, 1, 0, 0],
//  [0, 0, 0, 1, 0, 0]]

// 請完成樣板中的 create 函數，用傳入點以及adjacency matrix 後建立點跟點的關係
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Vertex
{
    struct Vertex *edgeList[100];
    int edgeCount;
    int id;
};

create(struct Vertex[10], int m[10][10])
{
}

void print(struct Vertex v[10])
{
    int j, k;
    for (j = 0; j < 10; j++)
    {
        printf("%d :", v[j].id);
        for (k = 0; k < v[j].edgeCount; k++)
        {
            printf(" %d", v[j].edgeList[k]->id);
        }
        printf("\n");
    }
}

int main()
{
    struct Vertex v[10];
    int j, k, i, l;
    int map[10][10];

    srand(time(NULL));
    //產生點
    for (j = 0; j < 10; j++)
    {
        v[j].id = j + 1;
        v[j].edgeCount = 0;
    }

    //建立 adjacency matrix
    for (j = 0; j < 10; j++)
    {
        for (k = 0; k < 10; k++)
        {
            if (rand() % 10 > 3)
                map[j][k] = 1;
            else
                map[j][k] = 0;
        }
    }

    //建圖
    create(v, map);

    print(v);
}
