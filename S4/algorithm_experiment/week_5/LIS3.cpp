#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

// Binary Search
int H_BS(int tar, int *dp, int *s, int left, int right)
{
    int mid = (left + right) / 2;
    if (mid == 0 || tar >= s[dp[mid - 1]] && tar < s[dp[mid]])
        return mid;
    if (tar < s[dp[mid - 1]])
        H_BS(tar, dp, s, left, mid);
    else if (tar >= s[dp[mid]])
        H_BS(tar, dp, s, mid + 1, right);
}

// Find the h(i) of the Longest Increasing Subsequence
int getHi(int *s, int i, int *dp, int &dp_n)
{
    if (dp_n == 0) // there's no value in dp Subsequence.
    {
        dp[dp_n++] = i;
        return -1;
    }
    if (s[i] >= s[dp[dp_n - 1]]) // Add a new node into dp Subsequence.
    {
        dp[dp_n++] = i;
        return dp[dp_n - 2];
    }

    int k = H_BS(s[i], dp, s, 0, dp_n);

    // Change the Value in dp Subsequence.
    dp[k] = i;
    if (k == 0)
        return -1;
    return dp[k - 1];
}

int *getLIS(int *s, int *h, int *f, int i)
{
    int *res = new int[f[i]];
    while (i > 0 && f[i - 1] == f[i])
        --i;
    int j = i;
    for (int k = f[i] - 1; k >= 0; --k)
    {
        res[k] = s[j];
        j = h[j];
    }

    return res;
}

int *LIS(int *s, int n, int &dp_n)
{
    int dp[n];
    int h[n];

    // Question 1
    for (int i = 0; i < n; ++i)
    {
        h[i] = getHi(s, i, dp, dp_n);
    }

    // Question 2
    int f[n];
    f[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        f[i] = 1;
        if (h[i] != -1 && f[h[i]] >= f[i - 1])
            f[i] = f[h[i]] + 1;
        else
            f[i] = f[i - 1];
    }

    // Question 3
    int i = n - 1;
    int *res = getLIS(s, h, f, i);

    cout << endl;
    cout << "S : ";
    for (int i = 0; i < n; ++i)
        cout << setw(2) << s[i] << " ";
    cout << endl;
    cout << "F : ";
    for (int i = 0; i < n; ++i)
        cout << setw(2) << f[i] << " ";
    cout << endl;
    cout << "H : ";
    for (int i = 0; i < n; ++i)
        cout << setw(2) << h[i] << " ";
    cout << endl;

    return res;
}

int main()
{
    // int s[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int s[] = {9, 7, 0, 1, 6, 3, 5, 8, 4};
    int n = sizeof(s) / sizeof(s[0]);

    int dp_n = 0;
    int *res = LIS(s, n, dp_n);

    for (int i = 0; i < dp_n; ++i)
        cout << res[i] << " ";

    return 0;
}