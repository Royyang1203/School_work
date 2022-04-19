#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct job
{
    int start;
    int end;
    int value;
};
bool cmp(job a, job b) { return a.end < b.end; } /// 依照結束時間由小到大排序

void find_p(int *p, job *work, int number) ///尋找上一個工作是誰
{
    for (int i = 1; i < number; i++)
        for (int j = i - 1; j >= 0; --j)
        {
            if (work[i].start >= work[j].end)
            {
                p[i] = j;
                break;
            }
            else
                p[i] = 0;
        }
}
int main()
{
    int n;
    cin >> n;
    job work[n + 1];
    int p[n + 1] = {0};

    work[0].start = work[0].end = work[0].value = 0;

    for (int i = 1; i <= n; i++)
        cin >> work[i].start >> work[i].end >> work[i].value; ///輸入工作

    sort(work, work + n + 1, cmp);
    find_p(p, work, n + 1); ///尋找每一個工作的上一個工作是誰

    /*for (int i = 0; i <= n; i++)
        cout<<work[i].end<<" ";
    for (int i = 0; i <= n; i++)
        cout<<p[i]<<" ";*/

    int m[n + 1] = {0};

    for (int i = 1; i <= n; i++)
        m[i] = max(m[i - 1], m[p[i]] + work[i].value);///判斷現在的工做是否in OPT

    for (int i = 0; i <= n; i++) cout << m[i] << " ";
}