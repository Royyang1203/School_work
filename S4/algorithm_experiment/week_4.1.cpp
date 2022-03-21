#include <iostream>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <algorithm>
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

float dist(Point p1, Point p2)
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
            if (dist(strip[i], strip[i + j]) < d)
                d = dist(strip[i], strip[i + j]);
        }
    }
    // cout << d << endl;
    return d;
}

/*
 * find the smallest distance.
 */
pair<Point, Point> closest_DC(Point Px[], Point Py[], int n, int left, int right)
{
    if (right - left == 2)
    {
        return pair<Point, Point>(Px[right], Px[left]);
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

    return min(d, stripClosest(strip, j, d));
}

/*
 * finds the smallest distance
 */
pair<Point, Point> closest(Point P[], int n)
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
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    // Point P[] = {{0, 2}, {6, 67}, {43, 71}, {39, 107}, {189, 140}};
    int n = sizeof(P) / sizeof(P[0]);
    pair<Point, Point> bipoint = closest(P, n);
    cout << "The smallest pair is "
         << "(" << bipoint.first.x << ", " << bipoint.first.y << ")"
         << "(" << bipoint.second.x << ", " << bipoint.second.y << ")";
    return 0;
}
