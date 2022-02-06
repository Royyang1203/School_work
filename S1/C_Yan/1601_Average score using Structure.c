// 內容：
// 程式必須包含以下兩部分：
// 使用結構：
// struct student {
// int grade[20];
// int count;
// }
// 實做function average_grade，
// double average_grade( struct student *std_ptf);

// 輸入說明：
// int 修課數量 < 20
// int 各科成績

// 輸出說明：
// 平均成績(double)，小數點後六位
// 範例輸入：
// 3
// 99 93 100
// 範例輸出：

// 97.333333

#include <stdio.h>

struct student
{
    double grade[20];
    int count;
};
double average_grade(struct student *a)
{
    int n = a->count, i;
    //printf("!!%d\n", n);
    double sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += a->grade[i];
    }

    return sum / n;
}

int main(void)
{
    int i;
    struct student a, b;
    struct student *ptr = &a;
    scanf("%d", &(a.count));
    double sum;
    for (i = 0; i < (a.count); i++)
    {
        scanf("%lf", &(a.grade[i]));
        sum += a.grade[i];
    }
    //printf("%lf\n", sum / a.count);
    printf("%lf\n", average_grade(&a));
    return 0;
}
