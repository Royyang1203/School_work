#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

void print_get_item(int *price, int *p, int i, int j, int m)
{
    if (p[i * (m + 1) + j] == 0)
        return;
    else if (p[i * (m + 1) + j] != p[(i - 1) * (m + 1) + j])
    {
        print_get_item(price, p, i - 1, j - price[i - 1], m);
        cout << i - 1 << " ";
    }
    else
    {
        print_get_item(price, p, i - 1, j, m);
    }
}

int knapsack_recur(int *v, int *w, int i, int j)
{
    if (i == 0)
        return 0;
    else if (w[i - 1] <= j)
        return max(knapsack_recur(v, w, i - 1, j), v[i - 1] + knapsack_recur(v, w, i - 1, j - w[i - 1]));
    else
        return knapsack_recur(v, w, i - 1, j);
}

void knapsack_dp(int *v, int *w, int *dp, int n, int m)
{
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (i == 0 || j == 0)
                dp[i * (m + 1) + j] = 0;
            else if (j < w[i - 1])
            {
                dp[i * (m + 1) + j] = dp[(i - 1) * (m + 1) + j];
            }
            else
            {
                dp[i * (m + 1) + j] = max(dp[(i - 1) * (m + 1) + j], dp[(i - 1) * (m + 1) + j - w[i - 1]] + v[i - 1]);
            }
        }
    }
}

int main()
{
    int n, m; // n 為可選的物品數量，m 為重量上限
    cin >> n >> m;
    int v[n], w[n];
    int *dp = new int[(n + 1) * (m + 1)];

    for (int i = 0; i < n; i++)
    {
        cin >> v[i] >> w[i];
    }

    knapsack_dp(v, w, dp, n, m);

    // for (int i = 0; i <= n; ++i)
    // {
    //     for (int j = 0; j <= m; ++j)
    //         cout << dp[i * (m + 1) + j] << " ";
    //     cout << endl;
    // }

    cout << knapsack_recur(v, w, n, m) << endl;
    cout << "maximum preference sum -> " << dp[n * (m + 1) + m] << endl;
    cout << "choose item index -> ";
    print_get_item(w, dp, n, m, m);
    return 0;
}

// test 1

// 4 5
// 10 1
// 12 1
// 15 2
// 20 3

// ans 1

// prefer : 10 + 12 + 20 = 42
// price : 1 + 1 + 3 <= 5
// index : 0, 1, 3

// test 2

// 5 8
// 4500 4
// 5700 5
// 2250 2
// 1100 1
// 6700 6

// ans 2

// prefer : 5700 + 2250 + 1100 = 9050
// price : 5 + 2 + 1 <= 8
// index : 1, 2, 3

// test 3

// 4 1000
// 1200 200
// 1500 500
// 1500 300
// 4000 850

// ans 3
// prefer : 1200 + 1500 + 1500 = 4200
// price : 200 + 500 + 300 <= 1000
// index : 0, 1, 2