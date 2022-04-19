#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define N 2005
#define M 10005

int w[N], sum[N], ans[N];

int main()
{
    int t, i, j, maxcar, m, n, maxlength;

    cin >> t;
    while (t--)
    {
        cin >> m;
        m *= 100;
        n = 0;
        sum[0] = 0;
        while (cin >> maxcar, maxcar)
        {
            ++n;
            w[n] = maxcar;
            sum[n] = sum[n - 1] + w[n];
        }
        int dp[n + 1][m + 1], pre[n = 1][m + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
            {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1; // 設為一代表此狀態可行，前項代表第幾個物件，後巷代表左邊現在長度
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