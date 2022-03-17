#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>

using namespace std;

inline bool check(double *pie, double x, int n, int f)
{
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += pie[i] / x;
    }
    return ans >= f;
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, f;
        cin >> n >> f;
        ++f;
        double max_piece = 0;
        double pie[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> pie[i];
            pie[i] = M_PI * pie[i] * pie[i];
            max_piece = max(max_piece, pie[i]);
        }
        double left = 0, right = max_piece;
        while (right - left > 1e-6)
        {
            double mid = (left + right) / 2;
            if (check(pie, mid, n, f))
                left = mid;
            else
                right = mid;
        }
        cout << setiosflags(ios::fixed) << setprecision(4) << left << endl;
    }
    return 0;
}
