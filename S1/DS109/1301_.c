// 請完成樣板中的 BFS 以及 DFS 函數，該函數會從傳入的點開始依照 BFS 或 DFS 的順序印出節點中的資料。
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Vertex
{
    struct Edge *edgeList[100];
    int edgeCount;
    int id;
};

struct Edge
{
    struct Vertex *end[2];
    int w;
};

void DFS(struct Vertex *v)
{
}

void BFS(struct Vertex *v)
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
            if (v[j].edgeList[k]->end[0] == &v[j])
                printf("%d ", v[j].edgeList[k]->end[1]->id);
            else
                printf("%d ", v[j].edgeList[k]->end[0]->id);
        }
        printf("\n");
    }
}

int main()
{
    struct Vertex v[10];
    struct Edge e[100];
    int j, k, i, l;

    srand(time(NULL));
    //產生點
    for (j = 0; j < 10; j++)
    {
        v[j].id = j + 1;
        v[j].edgeCount = 0;
    }

    //產生邊
    k = rand() % 20 + 1; //邊的數量
    for (j = 0; j < k; j++)
    {
        //先產生兩個端點
        i = rand() % 10;
        l = rand() % 10;
        //邊的重量
        e[j].w = rand() % 100;
        //兩個端點的連結
        e[j].end[0] = &v[i];
        e[j].end[1] = &v[l];
        printf("!!\n");
        //在兩個端點加入邊
        v[i].edgeList[v[i].edgeCount] = &e[j];
        v[i].edgeCount++;
        v[l].edgeList[v[l].edgeCount] = &e[j];
        v[l].edgeCount++;
    }
    print(v);
    for (j = 0; j < 10; j++)
    {
        BFS(&v[j]);
        printf("\n");
        DFS(&v[j]);
        printf("\n");
    }
}