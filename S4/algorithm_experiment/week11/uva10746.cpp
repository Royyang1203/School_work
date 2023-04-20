#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 9999999999999
#define eps 0.00000000001

vector<int> edge[50];
int cap[50][50], flow[50][50], pre[50];
double cost[50][50], dis[50];

void Initial(int S, int T, int N, int M);
double MCMF(int S, int T);
bool SPFA(int S, int T);
void UpdateFlow(int S, int T, int bottleneck);

int main()
{
    int N, M;
    while (scanf("%d %d", &N, &M) && (N || M))
    {
        int S = 0,
            T = N + M + 1;
        Initial(S, T, N, M);

        double travel_time;
        for (int i = 1; i <= N; ++i)
        {
            for (int j = N + 1; j <= N + M; ++j)
            {
                scanf("%lf", &travel_time);
                cost[i][j] = travel_time;
            }
        }
        printf("%.2f\n", MCMF(S, T) / N + eps);
    }
}
void Initial(int S, int T, int N, int M)
{
    for (int i = S; i <= T; ++i)
        edge[i].clear();
    memset(cap, 0, sizeof(cap));
    memset(flow, 0, sizeof(flow));
    memset(cost, 0, sizeof(cost));

    for (int i = 1; i <= N; ++i)
    {
        cap[S][i] = 1; // connect S to all banks
        edge[S].push_back(i);
    }
    for (int i = N + 1; i <= N + M; ++i)
    {
        cap[i][T] = 1; // connect all police to T
        edge[i].push_back(T);
    }
    for (int i = 1; i <= N; ++i)
        for (int j = N + 1; j <= N + M; ++j)
        {
            cap[i][j] = 1; // connect all banks to all police
            edge[i].push_back(j);
            edge[j].push_back(i);
        }
}
double MCMF(int S, int T)
{
    double min_cost = 0;
    while (SPFA(S, T))
    {
        UpdateFlow(S, T, 1);
        min_cost += dis[T];
    }
    return min_cost;
}
bool SPFA(int S, int T)
{
    fill(begin(dis), end(dis), INF);
    queue<int> Q;
    bool inQueue[50] = {0};

    dis[S] = 0;
    Q.push(S);
    inQueue[S] = true;

    while (!Q.empty())
    {
        int cur = Q.front();
        inQueue[cur] = false;
        Q.pop();

        for (int nxt : edge[cur])
        {
            if (flow[nxt][cur] > 0 && dis[cur] + (-cost[nxt][cur]) < dis[nxt])
            {
                dis[nxt] = dis[cur] + (-cost[nxt][cur]);
                pre[nxt] = cur;
                if (!inQueue[nxt])
                {
                    inQueue[nxt] = true;
                    Q.push(nxt);
                }
            }
            else if (cap[cur][nxt] > flow[cur][nxt] && dis[cur] + cost[cur][nxt] < dis[nxt])
            {
                dis[nxt] = dis[cur] + cost[cur][nxt];
                pre[nxt] = cur;
                if (!inQueue[nxt])
                {
                    inQueue[nxt] = true;
                    Q.push(nxt);
                }
            }
        }
    }
    if (dis[T] == INF)
        return false;
    else
        return true;
}
void UpdateFlow(int S, int T, int bottleneck)
{
    for (int cur = T; cur != S; cur = pre[cur])
    {
        flow[pre[cur]][cur] += bottleneck;
        flow[cur][pre[cur]] -= bottleneck;
    }
}