#include <bits/stdc++.h>
// #include <vecotr>
using namespace std;
const double INF = 100000.0;
const int MAX_N = 60;
// const int start = 1; // vertax 1 為起點
// int N = 20;
// int m = 1 << N;
// double dp[1048576][MAX_N];
// int parents[1048576][MAX_N];

struct point
{
    double x;
    double y;
};

class Solution
{
    int n;
    long long m;
    int start = 1;

    point city[MAX_N];
    double adj[MAX_N][MAX_N];
    double **dp;
    int **parents;

public:
    Solution(vector<vector<double>> &data)
    {
        n = data.size();
        m = 1 << data.size();

        dp = new double *[m];
        parents = new int *[m];
        for (int i = 0; i < m; ++i)
        {
            dp[i] = new double[n];
            parents[i] = new int[n];
        }
        for (int i = 0; i < n; i++)
        {
            city[i + 1].x = data[i][1];
            city[i + 1].y = data[i][2];
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    adj[i][j] = INF;
                else
                {
                    adj[i][j] = abs(city_dis(i, j));
                }
            }
        }
    }
    ~Solution()
    {
        for (int i = 0; i < m; i++)
        {
            delete[] parents[i];
            delete[] dp[i];
        }
        delete[] parents;
        delete[] dp;
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
        for (int j = 1; j <= n; j++)
            if (i != j)
                temp = min(temp, adj[i][j]);

        return temp;
    }
    void print()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                printf("%11.2f", adj[i][j]);
            cout << endl;
        }
    }
    void solve()
    {

        for (int i = 0; i < m; i++) ///初始化
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = INT_MAX / 2;
                parents[i][j] = -1;
            }
        for (int i = 0; i < n; i++)
            dp[1 << i][i] = 0.0; //代表以哪個起點開始走，並設為0

        for (int Set = 0; Set < m; Set++) /// row（Set 代表我現在已走過哪些city)
        {

            for (int last = 0; last < n; last++) // col。（last 代表在所有走過的city中，最後一個city，所以last必定是Set裡其中一位)
            {
                if (last == start - 1 || ((Set & (1 << (start - 1))) == 0) || ((Set & (1 << last)) == 0))
                    continue; //判斷此last是否在Set中，方法：將1左移到那個城市的位元並與set做AND,0代表不存在

                int set_prev = Set - (1 << last); //假設Set={BCD},且B為最後一個，那可能為：CDB、DCB，所以要先求Set{CD}的時候，用DP表求min

                if (set_prev == 0) //假设今天只有一个城市:001、010、100， 所以当我减掉最后一个城市时，會變成000，因為他前面沒有城市，所以不需要判斷他前面是誰，只要回傳自己的字串的長度
                {
                    continue;
                }
                for (int last_prev = 0; last_prev < n; last_prev++) // 暴力搜（這裡就是找，B前面的是C還是D）
                {
                    if ((set_prev & (1 << last_prev)) == 0)
                        continue;                                                                                                                                                   // ast_prev必屬於set_prev
                    if ((dp[set_prev][last_prev] != INT_MAX / 2 && adj[last_prev + 1][last + 1] != INF) && dp[set_prev][last_prev] + adj[last_prev + 1][last + 1] <= dp[Set][last]) // Set{CD}中，以C結尾再加C->B的結尾與以D結尾再加D->B求min
                    {
                        dp[Set][last] = dp[set_prev][last_prev] + adj[last_prev + 1][last + 1];
                        parents[Set][last] = last_prev;
                    }
                }
            }
        }

        double ret = INT_MAX * 1.0;
        int tail = 0;
        for (int last = 0; last < n; last++) /// search最後一個(dp[m-1][last]不一定是最短的要搞清楚！！！！！)
        {
            if (dp[m - 1][last] < ret)
            {
                ret = dp[m - 1][last];
                tail = last;
            }
        }
        cout << ret + adj[tail + 1][start] << endl;

        ////////backtracking 找路徑
        vector<int> path;
        path.push_back(start); //要回到起點
        path.push_back(tail + 1);
        int Set = m - 1;
        int last = tail;
        while (parents[Set][last] != -1)
        {
            int last_prev = parents[Set][last];
            path.push_back(last_prev + 1);
            Set = Set - (1 << last); ///假設ABCD且C為最後一個，那我將C放入stack，再跳到ABD ，以此類推直到parents[Set][last] == -1
            last = last_prev;
        }
        reverse(path.begin(), path.end()); ///要反轉(因為是回推)
        // cout << "path: ";

        // for (unsigned int i = 0; i < path.size(); i++)
        // {
        //     cout << path[i] << " ";
        //     if (i != path.size() - 1)
        //         cout << "-> ";
        // }
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

    clock_t end_time = clock();
    cout << "Running time : " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
}
