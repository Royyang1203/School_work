#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool cmp(pair<double, double> a, pair<double, double> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    else
        return a.first < b.first;
}

int main()
{
    int n;
    double p, r; // position, radius
    double l, w, dx;

    while (cin >> n >> l >> w)
    {
        w /= 2.0;
        vector<pair<double, double>> v;
        for (int i = 0; i < n; i++)
        {
            cin >> p >> r;
            //排除沒用的噴水頭，避免對負數開根號
            if (r > w)
            {
                //轉換成區間覆蓋問題，長度應為圓能在草地上邊或下邊的最大長度
                dx = sqrt(r * r - w * w);
                v.push_back({p - dx, p + dx});
            }
        }
        // 排序
        sort(v.begin(), v.end(), cmp);

        int ans = 0;
        double right = 0.0;

        // for (int i = 0; i < v.size(); ++i)
        // {
        //     cout << v[i].first << " " << v[i].second << endl;
        // }

        for (int i = 0; i < v.size();)
        {
            // 因為已排序，第一個如果無法覆蓋，後面的也不可能覆蓋
            if (v[i].first > right)
                break;
            // 往後面檢查所有 v[i].first <= right 之元素，藉由 greedy 選出覆蓋最大者
            int j = i;
            for (; i < v.size() && v[i].first <= right; ++i)
            {
                // 如果比目前的父愛範圍更大，則更新
                if (v[i].second > v[j].second)
                {
                    j = i;
                }
            }
            // 選定此噴水頭
            ans++;
            // 更新 right
            right = v[j].second;
            // 已覆蓋全部區域
            if (right >= l)
                break;
        }

        // 如果有辦法覆蓋，則 right 必大於等於 l
        if (right >= l)
            cout << ans << "\n";
        // 中途退出則此時 right < l
        else
            cout << "-1\n";
    }
    return 0;
}