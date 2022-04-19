#include<iostream>
#include<algorithm>
using namespace std;
# define INF 99999
struct edge
{
    int s;
    int e;
    int w;
};
//教學影片:https://www.youtube.com/watch?v=-W4ZSe4ksaI
/// prim 與 dijkstra 很像，都是從點下手以及greedy得想法
int cmp(edge a,edge b){ return a.w<b.w;}

int Prim(int number,int start)
{ 
    int adj_matrix[number][number],occupy[number]={0};///p為判斷是否被佔領
    int dist[number]={0},last[number]={0}; ///特定的某個點到所有點的距離
    int a,b,tmp;
    edge E[number-1]; ///所有邊

    for(int i=0;i<number;i++)
        for(int j=0;j<number;j++)
            adj_matrix[i][j]=INF;

    while (cin>>a>>b>>tmp) {adj_matrix[b][a] = adj_matrix[a][b] = tmp;} ///建立adjency matrix(無向圖)
    //while (cin>>a>>b>>tmp) {adj_matrix[a][b] = tmp;}///建立adjency matrix(有向圖)

    /*for(int i=1;i<number;i++)
    {
        for(int j=1;j<number;j++)
            printf("%6d ",adj_matrix[i][j]);
        cout<<endl;
    }
    cout<<"//////////"<<endl;*/

    for (int i = 0; i < number; i++) 
    {
        dist[i] = adj_matrix[start][i]; //用 dist[]紀錄start到所有點的距離;
        if (dist[i] == INF)
            last[i] = -1;
        else
            last[i] = start;
    }
    occupy[start]=1; ///將起始點放入被佔領的集合

    int result=0,count=0; ///result = 所需花費，count = 計算邊數

    for(int i=1;i<number-1;i++)//要找到n-1個邊(因為當樹有n個點，則必有n-1條邊)
    {
        int temp = INF,t=start;

        for(int j=1;j<number;j++)///找距離最近的點
            if( !occupy[j] && dist[j]<temp)
            {
                t = j;
                temp = dist[j];
            }

        if(t==start) break;
        occupy[t] = 1 ;///將離最近的點放入被佔領的集合
        result += temp;///計算選擇這個點的邊所需花費
        
        for(int j=1;j<number;j++)
        {
            if( !occupy[j] && adj_matrix[t][j] < dist[j]) ///尋找未被佔領 && 更新起點到各個點的距離
            {
                dist[j] = adj_matrix[t][j]; 
                last[j] = t;
            }
        }
        E[count].s = last[t];
        E[count].e =  t;
        count++;
    }
    for(int i=0;i<count;i++) 
    cout<<i<<"th selet edge: "<<E[i].s<<" "<<E[i].e<<endl;
    return result;
}

int main()
{
    int n,start=1,t;
    cin>>n;
    t=Prim(n+1,start);
    cout<<"minimum cost: "<<t;
}
/*
7
1 2 23
2 3 20
3 4 15
4 5 3 
5 6 17
6 1 28
7 1 36
7 2 1 
7 3 4 
7 4 9 
7 5 16
7 6 25
^Z
outout:
0th selet edge: 1 2
1th selet edge: 2 7
2th selet edge: 7 3
3th selet edge: 7 4
4th selet edge: 4 5
5th selet edge: 5 6
minimum cost: 57
6
1 2 20
2 4 10
4 5 60
5 6 80
3 6 100
1 3 40
2 3 70
2 5 5
2 6 10
^Z
output:
0th selet edge: 1 2
1th selet edge: 2 5
2th selet edge: 2 4
3th selet edge: 2 6
4th selet edge: 1 3
minimum cost: 85*/