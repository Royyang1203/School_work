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
int getH(int *s, int i, int *dp, int &dp_n)
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

    // Change the Value in my Temporary Subsequence.
    dp[k] = i;
    if (k == 0)
        return -1;
    return dp[k - 1];
}

int *LIS(int *s, int n, int &dp_n)
{
    int dp[n];
    int h[n];

    // Question 1
    for (int i = 0; i < n; ++i)
    {
        h[i] = getH(s, i, dp, dp_n);
    }

    int *res = new int[dp_n];
    int j = dp[dp_n - 1];
    for (int i = dp_n - 1; i >= 0; --i)
    {
        res[i] = s[j];
        j = h[j];
    }

    cout << endl;
    cout << "S : ";
    for (int i = 0; i < n; ++i)
        cout << setw(2) << s[i] << " ";
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

    int f[n], g[n], h[n];

    for (int i = 0; i < n; ++i)
        f[i] = g[i] = 1;
    for (int i = 0; i < n; ++i)
        h[i] = -1;

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (s[j] < s[i] && g[i] <= g[j])
            {
                g[i] = g[j] + 1;
                h[i] = j;
            }
        }
    }

    for (int i = 1; i < n; ++i)
    {
        if (g[i] > f[i - 1])
            f[i] = g[i];
        else
            f[i] = f[i - 1];
    }

    cout << "S : ";
    for (int i = 0; i < n; ++i)
        cout << setw(2) << s[i] << " ";
    cout << endl;
    cout << "F : ";
    for (int i = 0; i < n; ++i)
        cout << setw(2) << f[i] << " ";
    cout << endl;
    cout << "G : ";
    for (int i = 0; i < n; ++i)
        cout << setw(2) << g[i] << " ";
    cout << endl;
    cout << "H : ";
    for (int i = 0; i < n; ++i)
        cout << setw(2) << h[i] << " ";
    cout << endl;
    return 0;
}