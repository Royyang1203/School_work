#include <iostream>
#include <algorithm>
using namespace std;
// https://ithelp.ithome.com.tw/articles/10243421
void order(int i, int j, int **p)
{
    if (i == j)
        cout << "A" << i;
    else
    {
        int k = p[i][j];
        cout << "(";
        order(i, k, p);
        order(k + 1, j, p);
        cout << ")";
    }
}
int main()
{
    /// 10,4,5,20,2,50
    /// 5,2,3,4,6,7,8
    /// 30,35,15,5,10,20,25

    int a[] = {
        20,
        3,
        10,
        36, 5, 3}; /// 4個矩陣
    int n = sizeof(a) / sizeof(a[0]);
    int m[n + 1][n + 1], p[n + 1][n + 1];

    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < n + 1; j++)
        {
            m[i][j] = 0;
            p[i][j] = 0;
        }

    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i <= n - l; i++)
        {
            int j = i + l - 1; ///起始陣列 + 有幾個矩陣相乘 -1 = 結尾陣列
            m[i][j] = 9999999;
            for (int k = i; k < j; k++) /// k = 結尾陣列到起始陣列之間有幾個陣列
            {
                int q = m[i][k] + m[k + 1][j] + a[k] * a[i - 1] * a[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    p[i][j] = k;
                }
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
            printf("%8d", m[i][j]);
        cout << endl;
    }
    cout << endl
         << endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
            printf("%8d", p[i][j]);
        cout << endl;
    }
    int *copy[n];
    for (int i = 0; i < n; i++)
        copy[i] = p[i];
    order(1, n - 1, copy);
}
