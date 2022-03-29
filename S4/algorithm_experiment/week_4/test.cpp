#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
const int INF = (int)1e4;
bool compare(const pair<int, int> &data_1, const pair<int, int> &data_2)
{
    return data_1.second < data_2.second;
}
double distance(const pair<int, int> &data_1, const pair<int, int> &data_2)
{
    return sqrt(pow(data_1.first - data_2.first, 2) + pow(data_1.second - data_2.second, 2));
}
double Closest_point(pair<int, int> point[], int low, int upp)
{
    if (low >= upp)
        return INF;
    int mid = (low + upp) / 2, index = 0;
    double line = (point[mid].first + point[mid + 1].first) / 2;
    pair<int, int> temp[upp - low + 1];
    double delta = min(Closest_point(point, low, mid), Closest_point(point, mid + 1, upp));
    for (int i = mid + 1; i <= upp && point[i].first < line + delta; ++i)
        temp[index++] = point[i];
    for (int i = mid; i >= low && point[i].first > line - delta; --i)
        temp[index++] = point[i];
    cout << delta << " " << index << endl;
    sort(temp, temp + index, compare);
    for (int i = 0; i < index; i++)
        for (int j = 1; j <= 7 && (i + j) < index; j++)
            delta = min(delta, distance(temp[i], temp[i + j]));
    return delta;
}
int main()
{
    int num;
    while (cin >> num && num)
    {
        pair<int, int> point[num], temp[num];
        for (int i = 0; i < num; ++i)
            cin >> point[i].first >> point[i].second;
        sort(point, point + num);
        double min = Closest_point(point, 0, num - 1);
        if (min >= 1e4)
            cout << "INFINITY\n";
        else
            cout << setprecision(4) << fixed << min << '\n';
    }
}