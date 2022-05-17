#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define N 2005

int w[N], sum[N], ans[N]; // 分別為第n臺車的長度, 到第n臺的長度加總, 記錄第n臺車的答案類別

int main()
{
    int t, i, j, maxcar, m, n, maxlength;

    cin >> t; // 測資數量
    while (t--)
    {
        cin >> m; // 橋的長度
        m *= 100;
        n = 0; // 車子數量
        sum[0] = 0;
        while (cin >> maxcar, maxcar) // 輸入長度, 會存在index one to n
        {
            ++n;
            w[n] = maxcar;
            sum[n] = sum[n - 1] + w[n];
        }
        // 第一個二維表存放到第n臺車時，左邊的橋上總長度維m時是否可行，後一個則是其上一個狀態的左橋總長度
        int dp[n + 1][m + 1], pre[n + 1][m + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
            {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1; // 設為一代表此狀態可行
        maxlength = -1;
        for (i = 1; i <= n; i++)
        {
            for (j = 0; j <= m; j++)
            {
                if (j >= w[i] && dp[i - 1][j - w[i]]) // 放左邊
                {
                    maxcar = i;    // 最大車輛數
                    maxlength = j; // 更新最長值
                    dp[i][j] = 1;
                    pre[i][j] = j - w[i]; // 記錄放左邊
                }
                else if (sum[i] - j <= m && dp[i - 1][j]) // 放右邊
                {
                    maxcar = i;    // 最大車輛數
                    maxlength = j; // 更新最長值
                    dp[i][j] = 1;
                    pre[i][j] = j; // 紀錄放右邊
                }
            }
        }
        // 由最大車輛數跟二維表，我們可以根據紀錄知道該臺車輛放哪邊
        i = maxcar;
        while (i--)
        {
            j = pre[i + 1][maxlength];
            if (j == maxlength)
                ans[i] = 1;
            else
                ans[i] = 0;
            maxlength = j;
        }
        // 印出答案
        cout << maxcar << endl;
        for (i = 0; i < maxcar; i++)
        {
            if (ans[i])
                cout << "starboard" << endl;
            else
                cout << "port" << endl;
        }
        if (t)
            cout << endl;
    }
    return 0;
}