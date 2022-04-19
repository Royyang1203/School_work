#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
#define INF 99999
///教學:https://www.youtube.com/watch?v=NX2Qf0c75Og
void find_path(int *p, int start, int end)
{
    stack<int> s;
    s.push(end);
    int temp = p[end];
    while (temp != start)
    {
        // cout<<temp<<" ";
        s.push(temp);
        temp = p[temp];
    }
    s.push(start);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}
int main()
{
    int n,start,end;
    cin >> n >>start>>end;
    int matrix[n + 1][n + 1]; //adjacency matrix

    for (int i = 0; i <= n; i++)        //建立adjacency matrix(鄰接矩陣)
        for (int j = 0; j <= n; j++)
            cin >> matrix[i][j];

   /*for (int i = 0; i <= n; i++) //print adjacency matrix
    {
        for (int j = 0; j <= n; j++)
            printf("%6d ", matrix[i][j]);
        cout << endl;
    }*/
    int dist[n + 1], check[n + 1] = {0}, p[n + 1];
    /*dist[] = 起點到某點的距離 
      check[] = 判斷此點是否已包含在被佔領
      p[] = 知道上個點是誰，為了找出最短路徑*/ 

    check[start] = 1; ///起點已被佔領

    for (int i = 0; i <= n; i++) //尤其點向外延伸去找距離最短距離的點
    {
        dist[i] = matrix[start][i]; //用 dist[]紀錄start到所有點的距離;
        if (dist[i] == INF)
            p[i] = -1;
        else
            p[i] = start;
    }
    /*for(int j=1;j<=n;j++) printf("%6d ",dist[j]);*/
    for (int i = 0; i < n; i++) 
    {
        int temp = INF, t = start;
        for (int j = 1; j <= n; j++)
        {
            if (!check[j] && dist[j] < temp)//找出未被佔領 && 距離最近的點
            {
                t = j;
                temp = dist[j];
            }
        }
        if(t==start) break; ///沒找到 跳出
        check[t] = 1; ///把距離最近的點加入佔領區

        for (int j = 0; j <= n; j++)
        {
            if (!check[j] && matrix[t][j] + dist[t] < dist[j]) //更新起點到各個點的距離
            {
                dist[j] = matrix[t][j] + dist[t];
                
                p[j] = t; ///紀錄上一個點
            }
        }
    }
   // for(int j=1;j<=n;j++) printf("%6d ",dist[j]);  //某個點到所有點最短距離

    cout << "p[i] :" << endl;
    for (int j = 0; j <= n; j++) printf("%6d ", p[j]);

    cout << endl << "short path: ";
    find_path(p, start, end);

    return 0;
}
/*input:
8 5 1
     0      0      0      0      0      0      0      0      0 
     0      0    300   1000  99999  99999  99999  99999   1700 
     0    300      0    800  99999  99999  99999  99999  99999
     0   1000    800      0   1200  99999  99999  99999  99999 
     0  99999  99999   1200      0   1500   1000  99999  99999
     0  99999  99999  99999   1500      0    250  99999  99999
     0  99999  99999  99999   1000    250      0    900   1400 
     0  99999  99999  99999  99999  99999    900      0   1000
     0   1700  99999  99999  99999  99999   1400   1000      0 

output
p[i] :
     5      8      3      4      6      5      5      6      6
short path: 5 6 8 1

5 1 5
     0      0      0      0      0      0 
     0  99999      2      5  99999  99999
     0  99999  99999      2      6  99999
     0  99999  99999  99999      7      1
     0  99999  99999      2  99999      4
     0  99999  99999  99999  99999  99999 
output
p[i] :
     1     -1      1      2      2      3
short path: 1 2 3 5

5 1 2
     0      0      0      0      0      0 
     0  99999      7      4      6      1
     0  99999  99999  99999  99999  99999
     0  99999      2  99999      5  99999
     0  99999      3  99999  99999  99999
     0  99999  99999  99999      1  99999 
p[i] :
     1     -1      4      1      5      1
short path: 1 5 4 2

8 5 1
0       0       0       0       0       0       0       0       0
0       99999   99999   99999   99999   99999   99999   99999   99999
0       300     99999   99999   99999   99999   99999   99999   99999
0       1000    800     99999   99999   99999   99999   99999   99999
0       99999   99999   1200    99999   99999   99999   99999   99999
0       99999   99999   99999   1500    99999   250     99999   99999
0       99999   99999   99999   1000    99999   99999   900     1400
0       99999   99999   99999   99999   99999   99999   99999   1000
0       1700    99999   99999   99999   99999   99999   99999   99999
p[i] :
     5      8      3      4      6     -1      5      6      6
short path: 5 6 8 */

