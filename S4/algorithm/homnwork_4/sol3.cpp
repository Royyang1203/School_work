#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

#define _MAX 1000 // MAX 應大於最大可能的長度，也就是在 set 中所有字串長度之和
using namespace std;

class Solution
{
public:
    // 此問題希望我們能找到最短的 super string，也就是重疊的字母越多越好
    // 這裡使用 DP 來解題，dp[] 代表著在選定之 set 中的字串，以第 k 個字串為字串之尾的狀況下，的最短 super string 長度
    // 每個 superstring 可由其去掉結尾字串所構成的 super string
    // 最小的狀態為單一個字串
    string shortestSuperstring(vector<string> &A)
    {
        int N = A.size(); // N 為測資長度
        // 這裡先計算所有字串之間相互連接時，可以重疊多少
        // 可以理解為，兩字串相接時，其增加的長度最少
        auto graph = vector<vector<int>>(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (i != j)
                    graph[i][j] = cal(A[i], A[j]);

        int M = 1 << N;

        // dp 代表著在選定之 set 中的字串，以第 k 個字串為字串之尾的狀況下，的最短 superstring 長度
        auto dp = vector<vector<int>>(M, vector<int>(N, _MAX));
        // 為了最後能找出此字串，我們要紀錄其前一個狀態
        auto parent = vector<vector<int>>(M, vector<int>(N, -1));
        for (int i = 0; i < N; i++)
            dp[1 << i][i] = A[i].size();

        for (int mask = 0; mask < M; mask++)
            for (int bit = 0; bit < N; bit++)
            {
                if ((mask & (1 << bit)) == 0)
                    continue;
                int pmask = mask ^ (1 << bit);
                // we want to update dp[mask][bit] = min_{i}(dp[pmask][i]+graph[i][bit])
                // where bit must be in mask, and i must be within pmask

                for (int i = 0; i < N; i++)
                {
                    if ((pmask & (1 << i)) == 0)
                        continue;
                    if (dp[pmask][i] + graph[i][bit] < dp[mask][bit])
                    {
                        dp[mask][bit] = dp[pmask][i] + graph[i][bit];
                        parent[mask][bit] = i;
                    }
                }
            }

        int start;
        int count = _MAX;
        for (int i = 0; i < N; i++)
            if (dp[M - 1][i] < count)
            {
                count = dp[M - 1][i];
                start = i;
            }

        int mask = M - 1;
        vector<int> path({start});
        while (parent[mask][start] != -1)
        {
            int next = parent[mask][start];
            path.push_back(next);
            mask = mask ^ (1 << start);
            start = next;
        }

        reverse(path.begin(), path.end());
        string result = A[path[0]];
        for (int i = 1; i < path.size(); i++)
            result = combine(result, A[path[i]]);

        return result;
    }

    int cal(string S, string T)
    {
        // 計算在 S 後面加入 T 時，superstring 的長度會增加多少，愈少愈好
        for (int k = min(S.size(), T.size()); k >= 0; k--)
        {
            if (S.substr(S.size() - k) == T.substr(0, k))
                return T.size() - k;
        }
        return 0;
    }

    string combine(string S, string T)
    {
        // 將 S 跟 T 組合為一個 superstring
        for (int k = min(S.size(), T.size()); k >= 0; k--)
        {
            if (S.substr(S.size() - k) == T.substr(0, k))
                return S + T.substr(k);
        }
        return S + T;
    }
};

int main()
{
    string s;
    vector<string> vec;
    while (cin >> s)
    {
        vec.push_back(s);
    }
    Solution sol;
    cout << sol.shortestSuperstring(vec);
    return 0;
}