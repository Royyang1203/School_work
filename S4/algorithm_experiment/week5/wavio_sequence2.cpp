#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int BS(int tar, int *dp, int left, int right)
{
    int mid = (left + right) / 2;
    if (mid == 0 || tar > dp[mid - 1] && tar <= dp[mid])
        return mid;
    if (tar <= dp[mid - 1])
        return BS(tar, dp, left, mid);
    else if (tar > dp[mid])
        return BS(tar, dp, mid + 1, right);
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int num[n];
        for (int i = 0; i < n; ++i)
            scanf("%d", &num[i]);

        int lis_n = 0, lds_n = 0;
        int lis_f[n];
        int lis[n];
        int lds_f[n];
        int lds[n];
        for (int i = 0, j = n - 1; i < n; ++i, --j)
        {
            if (lis_n == 0 || num[i] > lis[lis_n - 1])
            {
                lis[lis_n++] = num[i];
                lis_f[i] = lis_n - 1;
            }
            else
            {
                int t = BS(num[i], lis, 0, lis_n);
                lis[t] = num[i];
                lis_f[i] = t;
            }
            if (lds_n == 0 || num[j] > lds[lds_n - 1])
            {
                lds[lds_n++] = num[j];
                lds_f[j] = lds_n - 1;
            }
            else
            {
                int t = BS(num[j], lds, 0, lds_n);
                lds[t] = num[j];
                lds_f[j] = t;
            }
        }

        // for (int i = 0; i < n; ++i)
        // {
        //     cout << lis_f[i] << " ";
        // }
        // cout << endl;
        // for (int i = n - 1; i > 0; --i)
        // {
        //     cout << lis_f[i] << " ";
        // }
        // cout << endl;

        int Max = 0;
        for (int i = 0; i < n; ++i)
            if (min(lis_f[i], lds_f[i]) > Max)
                Max = min(lis_f[i], lds_f[i]);
        printf("%d\n", 2 * Max + 1);
    }
}
