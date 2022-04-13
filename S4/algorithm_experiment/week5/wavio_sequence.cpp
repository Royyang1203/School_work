#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

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
            // LIS
            int k = 0;
            while (num[i] > lis[k] && k < lis_n)
                ++k;
            if (k == lis_n)
            {
                lis[lis_n++] = num[i];
            }
            else if (num[i] < lis[k])
                lis[k] = num[i];

            lis_f[i] = k;

            // LDS
            k = 0;
            while (num[j] > lds[k] && k < lds_n)
                ++k;
            if (k == lds_n)
            {
                lds[lds_n++] = num[j];
            }
            else if (num[j] < lds[k])
                lds[k] = num[j];

            lds_f[j] = k;
        }

        for (int i = 0; i < n; ++i)
        {
            cout << lis_f[i] << " ";
        }
        cout << endl;

        int Max = 0;
        for (int i = 0; i < n; ++i)
            if (min(lis_f[i], lds_f[i]) > Max)
                Max = min(lis_f[i], lds_f[i]);
        printf("%d\n", 2 * Max + 1);
    }
}
