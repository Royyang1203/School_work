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

double dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double dist(pair<Point, Point> bp)
{
    return dist(bp.first, bp.second);
}

pair<Point, Point> smallest_of_three(Point Px[], int left)
{
    double d1 = dist(Px[left], Px[left + 1]);
    double d2 = dist(Px[left], Px[left + 2]);
    double d3 = dist(Px[left + 1], Px[left + 2]);
    // cout << "small of three " << d1 << " " << d2 << " " << d3 << endl;
    if (d1 < d2 && d1 < d3)
    {
        // cout << "1" << endl;
        return pair<Point, Point>(Px[left], Px[left + 1]);
    }
    else if (d2 < d1 && d2 < d3)
    {
        // cout << "2" << endl;
        return pair<Point, Point>(Px[left], Px[left + 2]);
    }
    else
    {
        // cout << "3" << endl;
        return pair<Point, Point>(Px[left + 1], Px[left + 2]);
    }
}

/*
 * find the distance beween the closest points of strip of given size
 */
pair<Point, Point> stripClosest(Point strip[], int size, pair<Point, Point> d)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 1; j <= 5 && i + j < size; ++j)
        {
            if (dist(strip[i], strip[i + j]) < dist(d))
                d = pair<Point, Point>(strip[i], strip[i + j]);
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
    // cout << left << " " << right << endl;
    if (right - left == 2)
    {
        return pair<Point, Point>(Px[left + 1], Px[left]);
    }
    if (right - left == 3)
    {
        return smallest_of_three(Px, left);
    }

    int mid = (right + left) / 2;
    Point midPoint = Px[mid];

    pair<Point, Point> dl = closest_DC(Px, Py, n, left, mid);
    pair<Point, Point> dr = closest_DC(Px, Py, n, mid, right);

    // cout << "dist of two pair " << dist(dl) << " " << dist(dr) << endl;
    // 找出較小之pair
    pair<Point, Point> d;
    if (dist(dl) < dist(dr))
        d = dl;
    else
        d = dr;

    // cout << dist(d) << endl;
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        if (abs(Py[i].x - midPoint.x) < dist(d))
        {
            strip[j++] = Py[i];
        }
    }

    return stripClosest(strip, j, d);
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
    // Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    // Point P[] = {{0, 0}, {-2, 0}, {4, 0}, {1, 1}, {3, 3}, {-2, 2}, {5, 2}};
    // Point P[] = {{0, 2}, {6, 67}, {43, 71}, {39, 107}, {189, 140}};
    // int n = sizeof(P) / sizeof(P[0]);

    srand(9);
    int n = 200;
    int k = 1000;

    Point P[n];
    for (int i = 0; i < n; ++i)
    {
        P[i] = {rand() % k, rand() % k};
    }

    pair<Point, Point> bipoint = closest(P, n);
    cout << "The smallest pair is "
         << "(" << bipoint.first.x << ", " << bipoint.first.y << ") and "
         << "(" << bipoint.second.x << ", " << bipoint.second.y << ")"
         << ", distance is " << dist(bipoint);
    return 0;
}
