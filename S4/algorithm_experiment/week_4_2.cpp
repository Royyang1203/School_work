#include <iostream>
#include <cfloat>
#include <cstdlib>
#include <cmath>
using namespace std;

struct Point
{
    int x, y;
};

/*
 * sort array of points according to X coordinate
 */
int compareX(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

/*
 * sort array of points according to Y coordinate
 */
int compareY(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}

/*
 * find the distance between two points
 */
float dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

/*
 * return the smallest distance between two points
 */
float small_dist(Point P[], int left, int right)
{
    float min = FLT_MAX;
    for (int i = left; i < right; ++i)
    {
        for (int j = i + 1; j < right; ++j)
        {
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
        }
    }
    return min;
}

/*
 * find the distance beween the closest points of strip of given size
 */
double stripClosest(Point strip[], int size, double d)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 1; j < 4 && i + j < size; ++j)
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
float closest_DC(Point Px[], Point Py[], int n, int left, int right)
{
    // cout << left << " " << right << endl;
    // if (right - left == 2)
    // {
    //     return dist(Px[right], Px[left]);
    // }
    // if (right - left == 3)
    // {
    //     return min(Px[left], Px[left + 1]);
    // }
    if (right - left <= 3)
        return small_dist(Px, left, right);
    int mid = (right + left) / 2;
    Point midPoint = Px[mid];

    double dl = closest_DC(Px, Py, n, left, mid + 1);
    double dr = closest_DC(Px, Py, n, mid + 1, right);
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
float closest(Point P[], int n)
{
    Point Px[n];
    Point Py[n];
    for (int i = 0; i < n; ++i)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }
    qsort(Px, n, sizeof(Point), compareX);
    qsort(Py, n, sizeof(Point), compareY);
    return closest_DC(Px, Py, n, 0, n);
}

int main()
{
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    // Point P[] = {{0, 2}, {6, 67}, {43, 71}, {39, 107}, {189, 140}};
    int n = sizeof(P) / sizeof(P[0]);
    cout << "The smallest distance is " << closest(P, n);
    return 0;
}
