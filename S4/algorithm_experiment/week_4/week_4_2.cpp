#include <iostream>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Point
{
    int x, y;
};

int compareX(Point a, Point b)
{
    return a.x < b.x;
}

int compareY(Point a, Point b)
{
    return a.y < b.y;
}

inline double dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double stripClosest(Point strip[], int size, double d)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 1; j <= 7 && i + j < size; ++j)
        {
            d = min(d, dist(strip[i], strip[i + j]));
        }
    }
    return d;
}

double closest_DC(Point Px[], int n, int left, int right)
{
    if (right - left == 1)
        return 10001;
    if (right - left == 2)
    {
        return dist(Px[left], Px[left + 1]);
    }
    if (right - left == 3)
    {
        return min(min(dist(Px[left], Px[left + 1]), dist(Px[left], Px[left + 2])), dist(Px[left + 1], Px[left + 2]));
    }

    int mid = (right + left) / 2;
    Point midPoint = Px[mid];

    double dl = closest_DC(Px, n, left, mid);
    double dr = closest_DC(Px, n, mid, right);
    double d = min(dl, dr);

    Point strip[right - left + 1];
    int j = 0;
    for (int i = mid - 1; i >= left && midPoint.x - Px[i].x < d; --i)
        strip[j++] = Px[i];
    for (int i = mid; i <= right && Px[i].x - midPoint.x < d; ++i)
        strip[j++] = Px[i];
    sort(strip, strip + j, compareY);

    return stripClosest(strip, j, d);
}

double closest(Point P[], int n)
{
    Point Px[n];
    for (int i = 0; i < n; ++i)
    {
        Px[i] = P[i];
    }
    sort(Px, Px + n, compareX);

    return closest_DC(Px, n, 0, n);
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        Point p[n];
        for (int i = 0; i < n; ++i)
            cin >> p[i].x >> p[i].y;

        double d = closest(p, n);
        if (d >= 10000)
        {
            cout << "INFINITY" << endl;
        }
        else
        {
            cout << setiosflags(ios::fixed) << setprecision(4) << d << endl;
        }
    }

    return 0;
}
