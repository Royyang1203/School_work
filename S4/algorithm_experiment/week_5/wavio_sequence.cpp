#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int num[100001];
int LIS[100001]; // LIS的Stack
int lis[100001]; //每個數字LIS的表
int LDS[100001];
int lds[100001];
int LIS_Max, LDS_Max; // 表示LIS的Stack有幾層(level)

void LIS_function(int i);
void LDS_function(int i);

int main()
{
    // freopen("input.txt", "rt", stdin);
    while (scanf("%d", &N) != EOF)
    {
        LIS_Max = 0, LDS_Max = 0;
        for (int i = 0; i < N; ++i)
            scanf("%d", &num[i]);

        for (int i = 0, j = N - 1; i < N; ++i, --j)
        {
            LIS_function(i);
            LDS_function(j);
        }

        int Max = 0;
        for (int i = 0; i < N; ++i)
            if (min(lis[i], lds[i]) > Max)
                Max = min(lis[i], lds[i]);
        printf("%d\n", 2 * Max + 1);
    }
}
void LIS_function(int i)
{
    int j = 0;
    while (num[i] > LIS[j] && j < LIS_Max)
        ++j;
    if (j == LIS_Max)
    {
        LIS[LIS_Max] = num[i];
        ++LIS_Max;
    }
    else if (num[i] < LIS[j])
        LIS[j] = num[i];

    lis[i] = j;
}
void LDS_function(int i)
{
    int j = 0;
    while (num[i] > LDS[j] && j < LDS_Max)
        ++j;
    if (j == LDS_Max)
    {
        LDS[LDS_Max] = num[i];
        ++LDS_Max;
    }
    else if (num[i] < LDS[j])
        LDS[j] = num[i];

    lds[i] = j;
}