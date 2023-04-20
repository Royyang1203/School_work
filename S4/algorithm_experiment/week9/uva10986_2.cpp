#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define N 20000
using namespace std;

struct Node
{
    int v, w;
    Node() {}
    Node(int vv, int ww) : v(vv), w(ww) {}
    // priority queue 預設為由max heap，但我們要min heap，所以要故意定義相反，使結果為min heap
    bool operator<(const Node &a) const { return w > a.w; } //小的優先
};
vector<Node> list[N]; // adjacent list
int dijkstra(int s, int goal, int n);
int main()
{
    int Case;
    scanf("%d", &Case);
    for (int c = 1; c <= Case; c++)
    {
        int n, m, s, t, u, v, w, i;
        scanf("%d%d%d%d", &n, &m, &s, &t);

        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            // u 到 v
            list[u].push_back(Node(v, w));
            // v 到 u
            list[v].push_back(Node(u, w));
        }

        printf("Case #%d: ", c);
        int ans = dijkstra(s, t, n);
        // 會用到 n 個，將舊資料清除
        for (i = 0; i < n; i++)
            list[i].clear();
        if (ans == 1e9)
            puts("unreachable");
        else
            printf("%d\n", ans);
    }

    return 0;
}

int dijkstra(int s, int goal, int n)
{
    // 是否接觸此點
    bool isVisit[N] = {false};
    // 到此點的最短距離
    int d[N];
    // 先設為極大值
    fill(d, d + n, 1e9);
    // 初始點距離為零
    d[s] = 0;
    priority_queue<Node> PQ;
    PQ.push(Node(s, 0));

    while (true)
    {
        int next = -1;
        // 檢查是否接觸過此 node
        while (!PQ.empty() && isVisit[next = PQ.top().v])
            PQ.pop();
        // 如果此次選到的 node 為目標，就結束了，或是 queue 為空，無解
        if (next == -1 || next == goal)
            return d[goal];
        // 處理此點，並將其邊加入 queue 中
        isVisit[next] = true;

        for (Node node : list[next])
        {
            // 檢查此點是否為接觸，且要更新的答案較現存答案小(重邊)
            if (!isVisit[node.v] && d[next] + node.w < d[node.v])
            {
                d[node.v] = d[next] + node.w;
                PQ.push(Node(node.v, d[node.v]));
            }
        }
    }
    return d[goal];
}