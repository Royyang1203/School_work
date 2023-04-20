#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define pii pair<int, int>
#define P pair<long long, int>
#define F first
#define S second
#define INF 0x3F3F3F3F3F3F3F3F
const int maxn = 20000;

vector<pii> G[maxn];
long long dist[maxn];

int main()
{
    int N, n, m, S, T;
    int u, v, w;
    cin >> N;
    for (int Case = 1; Case <= N; Case++)
    {
        for (int i = 0; i < maxn; i++)
            G[i].clear();
        cin >> n >> m >> S >> T;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        // Dijkstra - priority_queue
        memset(dist, 0x3F, sizeof(dist));
        priority_queue<P, vector<P>, greater<P>> pq;
        dist[S] = 0;
        pq.push({0, S});
        while (!pq.empty())
        {
            P p = pq.top();
            pq.pop();
            if (dist[p.S] < p.F)
                continue;
            for (auto nxt : G[p.S])
            {
                if (dist[nxt.F] > dist[p.S] + nxt.S)
                {
                    dist[nxt.F] = dist[p.S] + nxt.S;
                    pq.push({dist[nxt.F], nxt.F});
                }
            }
        }
        cout << "Case #" << Case << ": ";
        if (dist[T] == INF)
            cout << "unreachable\n";
        else
            cout << dist[T] << '\n';
    }
    return 0;
}