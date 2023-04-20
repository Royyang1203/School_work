#include <bits/stdc++.h>
using namespace std;
const double INF = 100000.0;
const int MAX_N = 22;
const int start = 1; // vertax 1 為起點
int N = 20;
struct Node
{
    bool visited[MAX_N + 1]; //标记哪些点走了
    int path[MAX_N + 1];
    int s;       //第一个点
    int e;       //最后一个点
    int k = 0;   //走过的点数
    double sumv; //经过路径的距离
    bool operator<(const Node &p) const
    {
        return p.sumv < sumv; //目标函数值小的先出队列
    }
};
struct point
{
    double x;
    double y;
};
priority_queue<Node> pq; //创建一个优先队列

class Solution
{
public:
    void initial()
    {
        double min, x_, y_, temp, number;

        for (int i = 1; i <= N; i++)
        {
            cin >> number >> x_ >> y_;
            city[i].x = x_;
            city[i].y = y_;
        }
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i == j)
                    adj[i][j] = INF;
                else
                {
                    temp = abs(city_dis(i, j));
                    adj[i][j] = temp;
                }
            }
        }
        cout << "llllb" << lb << endl;
        for (int i = 1; i <= N; i++)
        { ///找出行最小
            min = min_col(i);
            cout << min << endl;
            lb += min;
            for (int j = 1; j <= N; j++)
                if (i != j)
                    adj[i][j] -= min;
        }
        cout << lb << endl;
        print();
    }
    double city_dis(int a, int b)
    {
        double temp_x, temp_y;
        temp_x = pow(city[a].x - city[b].x, 2);
        temp_y = pow(city[a].y - city[b].y, 2);
        return sqrt(temp_x + temp_y);
    }
    double min_col(int i)
    {
        double temp = 0x7f * 1.0;
        for (int j = 1; j <= N; j++)
            if (i != j)
                temp = min(temp, adj[i][j]);

        return temp;
    }
    void print()
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
                printf("%11.2f", adj[i][j]);
            cout << endl;
        }
    }
    void solve()
    {
        Node first;
        memset(first.visited, false, sizeof(first.visited));
        first.s = start;
        first.e = start;
        first.path[first.k++] = start;

        first.sumv = lb;
        first.visited[start] = true;

        double min_cost = INF;
        pq.push(first);
        while (!pq.empty())
        {
            Node tmp = pq.top();
            pq.pop();

            if (tmp.sumv > min_cost)
                continue;

            if (tmp.k == N - 1)
            { //如果已经走过了n-1个点
                int p = -1;
                for (int i = 1; i <= N; i++)
                {
                    if (!tmp.visited[i])
                    {          //找出最後那個沒有走過的點
                        p = i; //將沒走到的點設為最後一個點
                        break;
                    }
                }
                //將目前為只以走的距離+之前最後的點到最後一個未vis的點，再加上未vis的點走到起點
                double ans = tmp.sumv + adj[tmp.e][p] + adj[p][tmp.s];
                tmp.visited[p] = true;
                tmp.e = p;

                tmp.path[tmp.k++] = p;
                tmp.e = tmp.s;
                tmp.path[tmp.k++] = tmp.s;
                tmp.sumv = ans;
                if (ans < min_cost)
                {
                    min_cost = ans;
                    result = tmp;
                }
                continue;
            }
            //城市還沒走完
            Node next; //拓展下一個城市
            memset(next.visited, false, sizeof(next.visited));
            for (int i = 1; i <= N; i++)
            {
                if (!tmp.visited[i]) //尋找未visited的點
                {
                    next.s = tmp.s;                       //沿着tmp走到next，起點不變
                    next.sumv = tmp.sumv + adj[tmp.e][i]; //更新路径和
                    next.e = i;                           //更新最后一个点
                    for (int i = 0; i < tmp.k; i++)
                        next.path[i] = tmp.path[i]; //複製tmp的路徑到新的一個節點
                    next.path[tmp.k] = i;
                    next.k = tmp.k + 1; //更新已走過的城市數量
                    for (int j = 1; j <= N; j++)
                    {
                        next.visited[j] = tmp.visited[j]; // tmp的點也是next經過的點
                    }
                    next.visited[i] = true; //新找到的城市也要設為走過了

                    if (min_cost < next.sumv)
                        continue;

                    pq.push(next); //
                }
            }
        }
    }
    double lb;
    Node result;
    point city[MAX_N];
    double adj[MAX_N][MAX_N];
};

int main()
{
    Solution *sol = new Solution;
    sol->initial();
    sol->solve();
    for (int i = 0; i < sol->result.k; i++)
    {
        printf("%d", sol->result.path[i]);
        if (i != sol->result.k - 1)
            cout << "->";
    }
    printf("\nMin_cost: %.3lf", sol->result.sumv);
}
