// 請完成樣板中的 Prim's Algorithm 以及Kruskal's Algorithm
// #include<stdio.h>
// #include<stdlib.h>
// #include<time.h>

// struct Vertex
// {
// 	struct Edge *edgeList[100];
// 	int edgeCount;
// 	int id;
// };

// struct Edge
// {
// 	struct Vertex *end[2];
// 	int w;
// };

// //請把找到的邊存在 result
// void Kruskal(struct Vertex v[10], struct Edge e[100], struct Edge *result[100])
// {
// }

// //請把找到的邊存在 result
// //root 表示起點為 v[root]
// void prim(struct Vertex v[10], struct Edge e[100], struct Edge *result[100], int root)
// {
// }

// void print(struct Vertex v[10])
// {
// 	int j, k;
// 	for(j = 0;j < 10;j ++)
// 	{
// 		printf("%d :", v[j].id);
// 		for(k = 0;k < v[j].edgeCount;k ++)
// 		{
// 			if(v[j].edgeList[k]->end[0] == &v[j])
// 				printf("%d ", v[j].edgeList[k]->end[1]->id);
// 			else
// 				printf("%d ", v[j].edgeList[k]->end[0]->id);

// 		}
// 		printf("\n");
// 	}
// }

// int main()
// {
// 	struct Vertex v[10];
// 	struct Edge e[100];
// 	struct Edge *result[100];
// 	int j, k, i, l;

// 	srand(time(NULL));
// 	//產生點
// 	for(j = 0;j < 10;j ++)
// 	{
// 		v[j].id = j + 1;
// 		v[j].edgeCount = 0;
// 	}

// 	//產生邊
// 	k = rand() % 10 + 1; //邊的數量
// 	for(j = 0;j < k;j ++)
// 	{
// 		//先產生兩個端點
// 		i = rand() % 10;
// 		l = rand() % 10;
// 		//邊的重量
// 		e[j].w = rand() % 100;
// 		//兩個端點的連結
// 		e[j].end[0] = &v[i];
// 		e[j].end[1] = &v[l];
// 	printf("!!\n");
// 		//在兩個端點加入邊
// 		v[i].edgeList[v[i].edgeCount] = &e[j];
// 		v[i].edgeCount ++;
// 		v[l].edgeList[v[l].edgeCount] = &e[j];
// 		v[l].edgeCount ++;
// 	}

// 	Kruskal(v, e, result);
//     for(j = 0;j < 10;j ++)
// 		prim(v, e, result, j);
// }

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Vertex Vertex;

struct Vertex
{
	Vertex *edgeList[100];
	int edgeCount;
	int id;
};

void create_node(Vertex v[10], int m[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int h = 0; h < 10; h++)
		{
			if (m[i][h])
			{
				v[i].edgeList[v[i].edgeCount++] = &v[h];
			}
		}
	}
}

void print(Vertex v[10])
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
	Vertex v[10];
	int j, k, i, l;
	int map[10][10] = {0};

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
	create_node(v, map);

	print(v);
}
