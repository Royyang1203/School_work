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

/*
 * find the distance beween the closest points of strip of given size
 */
double stripClosest(Point strip[], int size, double d)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 1; j <= 5 && i + j < size; ++j)
        {
            d = min(d, dist(strip[i], strip[i + j]));
        }
    }
    return d;
}

/*
 * find the smallest distance.
 */
double closest_DC(Point Px[], Point Py[], int n, int left, int right)
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

    double dl = closest_DC(Px, Py, n, left, mid);
    double dr = closest_DC(Px, Py, n, mid, right);
    double d = min(dl, dr);

    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        if (abs(Py[i].x - midPoint.x) < d)
        {
            strip[j++] = Py[i];
        }
    }

    return stripClosest(strip, j, d);
}

/*
 * finds the smallest distance
 */
double closest(Point P[], int n)
{
    Point Px[n];
    Point Py[n];
    for (int i = 0; i < n; ++i)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }
    sort(Px, Px + n, compareX);
    sort(Py, Py + n, compareY);
    return closest_DC(Px, Py, n, 0, n);
}

int main()
{
    // freopen("2.in", "r", stdin);
    int n;
    while (cin >> n && n)
    {
        Point p[n];
        for (int i = 0; i < n; ++i)
            cin >> p[i].x >> p[i].y;

        // for (int i = 0; i < n; ++i)
        //     cout << p[i].x << " " << p[i].y << endl;
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
    // freopen("result.out", "w", stdout);

    return 0;
}
