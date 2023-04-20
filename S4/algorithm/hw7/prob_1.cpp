#include <bits/stdc++.h>
#define MAX 9999
using namespace std;
vector<double> minRow;
double minL = MAX; // for length
int CITIES;
class City
{
public:
    int id;
    int x;
    int y;
    City() {}
};

void Make_adj(vector<City> arr, vector<vector<double>> &edges)
{
    for (int c = 0; c < CITIES; c++)
        for (int cc = c + 1; cc < CITIES; cc++)
            edges[c][cc] = edges[cc][c] = sqrt((arr[c].x - arr[cc].x) * (arr[c].x - arr[cc].x) + (arr[c].y - arr[cc].y) * (arr[c].y - arr[cc].y));
}

double TSP(vector<vector<double>> &edges, vector<bool> visited, int current, int visit, double bound, double len)
{
    double minBound = MAX;
    if (visit == CITIES)
    {
        len = len + edges[0][current];
        if (len < minL)
            minL = len;
        return minL;
    }
    int minBound_id;
    double bounds[CITIES];
    double lens[CITIES];
    for (int i = 0; i < CITIES; i++) //建立bound表
    {
        if (i == current || visited[i]) //如果為已經過或是為當前點則bound=MAX，避免branch
            bounds[i] = lens[i] = MAX;
        else
        {
            bounds[i] = bound - minRow[current] + edges[current][i];
            lens[i] = len + edges[current][i];
            if (bounds[i] < minBound)
            {
                minBound = bounds[i]; //找到最小bound
                minBound_id = i;
            }
        }
    }
    if (minBound > minL) //當前的都很爛的話則退回
        return minL;
    vector<bool> localVisited = visited;
    while (1)
    {
        bool is_Found_min = false;
        double Min = minL;
        if (minL == MAX)
            Min = minBound;
        if (minBound_id != current && bounds[minBound_id] <= Min && !localVisited[minBound_id])
        {
            vector<bool> tempVisited = visited;
            tempVisited[minBound_id] = true;
            double new_minL = TSP(edges, tempVisited, minBound_id, visit + 1, bounds[minBound_id], lens[minBound_id]);
            if (new_minL <= minL)
                is_Found_min = true;
        }
        localVisited[minBound_id] = true;
        if (!is_Found_min) //沒有找到更好的
            break;
        bounds[minBound_id] = MAX;
        lens[minBound_id] = MAX;
        minBound = MAX;
        for (int i = 0; i < CITIES; ++i) //找其他更好的
            if (bounds[i] < minBound)
            {
                minBound = bounds[i];
                minBound_id = i;
            }
        if (minBound == MAX) //都不能走
            break;
    }
    return minL;
}

int main()
{
    vector<City> cities;
    City temp;
    while (cin >> temp.id)
    {
        cin >> temp.x;
        cin >> temp.y;
        cities.push_back(temp);
    }
    CITIES = cities.size();
    vector<vector<double>> edges(CITIES, vector<double>(CITIES));
    Make_adj(cities, edges);
    double minTotal = 0;
    for (int i = 0; i < CITIES; ++i) //為了確定界線，因此需要找最小值
    {
        double mindis = MAX;
        for (int j = 0; j < CITIES; ++j)
        {
            if (j == i)
                continue;
            if (edges[i][j] < mindis)
                mindis = edges[i][j];
        }
        minRow.push_back(mindis);
        minTotal += mindis; //最小值總和
    }

    vector<bool> visited; //行進路程檢查
    for (int i = 0; i < CITIES; ++i)
    {
        visited.push_back(false);
    }
    visited[0] = true; //設定第一個點

    double distance = TSP(edges, visited, 0, 1, minTotal, 0);
    cout << distance;
}
