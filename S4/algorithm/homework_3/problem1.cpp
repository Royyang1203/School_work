#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

void print_buy_item(int *price, int *p, int i, int j, int m)
{
    if (p[i * (m + 1) + j] == -1)
        return;
    else if (p[i * (m + 1) + j] == 1)
    {
        print_buy_item(price, p, i - 1, j - price[i - 1], m);
        cout << i - 1 << " ";
    }
    else
    {
        print_buy_item(price, p, i - 1, j, m);
    }
}

int main()
{
    int n, m; // n 為可選的物品數量，m 為預算上限
    cin >> n >> m;
    int prefer[n], price[n]; // prefer 為物品物品的喜好程度，price 為物品的價格
    int dp[n + 1][m + 1];
    int *p = new int[(n + 1) * (m + 1)]; // 紀錄是否有選擇此列之物品，如果有回傳 1 ，沒有則回傳 0 ，第零行跟第零列為 -1，當作結束遞迴之辨識

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            p[i * (m + 1) + j] = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> prefer[i] >> price[i];
    }

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (j < price[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
                p[i * (m + 1) + j] = 0;
            }
            else
            {
                if (dp[i - 1][j] > dp[i - 1][j - price[i - 1]] + prefer[i - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                    p[i * (m + 1) + j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - price[i - 1]] + prefer[i - 1];
                    p[i * (m + 1) + j] = 1;
                }
            }
        }
    }

    cout << "maximum preference sum -> " << dp[n][m] << endl;
    cout << "choose item index -> ";
    print_buy_item(price, p, n, m, m);
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