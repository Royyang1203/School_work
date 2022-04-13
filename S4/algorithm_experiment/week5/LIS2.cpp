#include <iostream>
#include <cstdlib>

int *LIS(int *s, int n)
{
    int *f = new int[n];
    int *g = new int[n];
    int *h = new int[n];

    for (int i = 0; i < n; i++)
        g[i] = 1;

    for (int i = 0; i < n; i++)
        h[i] = -1;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (s[i] < s[j])
                if (length[i] + 1 > length[j])
                {
                    length[j] = length[i] + 1;
                    // s[j] 接在 s[i] 後面
                    h[j] = i;
                }

    int l = 0, pos = 0;
    for (int i = 0; i < N; i++)
        if (length[i] > l)
        {
            l = length[i];
            pos = i;
        }

    // print_LIS(pos);
}

// // 遞迴版本
// void print_LIS(int i)
// {
//     if (prev[i] != -1)
//         print_LIS(prev[i]);
//     std::cout << s[i];
// }

// // 迴圈版本，LIS順序顛倒。
// // 暫時儲存於其他陣列，之後再依序印出。
// void print_LIS(int i)
// {
//     int l = length[i]; // LIS長度
//     for (; i != -1; i = prev[i])
//         lis[--l] = s[i];

//     l = length[i][j];
//     for (int i = 0; i < l; ++i)
//         std::cout << lis[i];
// }

using namespace std;
int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *res = LIS(arr, n);
    for (int i = 0; i < n; ++i)
        cout << res[i];

    return 0;
}