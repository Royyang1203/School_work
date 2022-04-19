#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct job
{
    int start;
    int end;
};
bool cmp(job a,job b) { return a.end<b.end;} /// 依照結束時間由小到大排序
int main()
{
    int n;
    cin>>n;
    job work[n];
    for(int i=0;i<n;i++) cin>>work[i].start>>work[i].end; ///輸入工作開始時間及結束時間

    sort(work,work+n,cmp);

    int time=0,number=0; ///time 紀錄現在時間在哪，number紀錄已執行幾個工作

    for(int i=0;i<n;i++)
        if(time<=work[i].start)
        {
            time = work[i].end;
            number++;
        }

    cout<<number;
}