#include <bits/stdc++.h>
using namespace std;
const double INF = 100000.0;
const int MAX_N = 24;
const int start = 1;
int N;

struct Node
{
    bool visited[MAX_N + 1];
    int path[MAX_N + 1];
    int s;
    int e;
    int k = 0;
    double sumv;
    bool operator<(const Node &p) const
    {
        return p.sumv < sumv; //
    }
};
struct point
{
    double x;
    double y;
};
priority_queue<Node> pq;

class Solution
{
public:
    // int N;
    double lb;
    Node result;
    point city[MAX_N];
    double adj[MAX_N][MAX_N];

    Solution(vector<vector<double>> &data)
    {
        N = data.size();

        for (int i = 0; i < N; i++)
        {
            city[i + 1].x = data[i][1];
            city[i + 1].y = data[i][2];
        }
        double min, temp;

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
        for (int i = 1; i <= N; i++) ///找出行最小
        {
            min = min_col(i);
            lb += min;
            for (int j = 1; j <= N; j++)
                if (i != j)
                    adj[i][j] -= min;
        }
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

            if (tmp.k == N - 1) //如果已经走过了n-1个点
            {
                int p = -1;
                for (int i = 1; i <= N; i++)
                {
                    if (!tmp.visited[i]) //找出最後那個沒有走過的點
                    {
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

                    pq.push(next);
                }
            }
        }
    }
};

int main()
{
    vector<vector<double>> data;
    double a, b, c;
    while (cin >> a >> b >> c)
    {
        vector<double> t;
        t.push_back(a);
        t.push_back(b);
        t.push_back(c);
        data.push_back(t);
    }

    clock_t start_time = clock();

    Solution *sol = new Solution(data);
    sol->solve();

    // for (int i = 0; i < sol->result.k; i++)
    // {
    //     printf("%d", sol->result.path[i]);
    //     if (i != sol->result.k - 1)
    //         cout << "->";
    // }

    cout << sol->result.sumv << endl;

    clock_t end_time = clock();
    cout << "Running time : " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
}
