// UVa 1032

// Description

// A research group is developing a computer program that will fetch historical stock market quotes from

// a service that charges a fixed fee for each day’s quotes that it delivers. The group has examined the

// collection of previously-requested quotes and discovered a lot of duplication, resulting in wasted money.

// So the new program will maintain a list of all past quotes requested by members of the group. When

// additional quotes are required, only quotes for those dates not previously obtained will be fetched from

// the service, thus minimizing the cost.

// You are to write a program that d etermines when new quotes are required. Input for the program

// consists of the date ranges for which quotes have been requested in the past and the date ranges for

// which quotes are required. The program will then determine the date ranges for which quotes must be

// fetched from the service.

// Input
// There will be multiple input cases. The input for each case begins with two non-negative integers NX

// and NR, (0 ≤ NX, NR ≤ 100). NX is the number of existing date ranges for quotes requested in

// the past. NR is the number of date ranges in the incoming requests for quotes. Following these are

// NX + NR pairs of dates. The first date in each pair will be less than or equal to the second date in

// the pair. The first NX pairs specify the date ranges of quotes which have been requested and obtained

// in the past, and the next NR pairs specify the date ranges for which quotes are required.

// Two zeroes will follow the input data for the last case.

// Each input date will be given in the form Y Y Y Y MMDD. Y Y Y Y is the year (1700 to 2100), MM

// is the month (01 to 12), and DD is the day (in the allowed range for the given month and year). Recall

// that months 04, 06, 09, and 11 have 30 days, months 01, 03, 05, 07, 08, 10, and 12 have 31 days, and

// month 02 has 28 days except in leap years, when it has 29 days. A year is a leap year if it is evenly

// divisible by 4 and is not a century year (a multiple of 100), or if it is divisible by 400.

// Output
// For each input case, display the case number (1, 2, . . . ) followed by a list of any date ranges for which

// quotes must be fetched from the service, one date range per output line. Use the American date format

// shown in the sample output below. Explicitly indicate (as shown) if no additional quotes must be

// fetched. If two date ranges are contiguous or overlap, then merge them into a single date range. If a

// date range consists of a single date, print it as a single date, not as a range consisting of two identical

// dates. Display the date ranges in chronological order, starting with the earliest date range.

// Sample Input 1

// 1 1
// 19900101 19901231
// 19901201 20000131
// 0 3
// 19720101 19720131
// 19720201 19720228
// 19720301 19720301
// 1 1
// 20010101 20011231
// 20010515 20010901
// 0 0
// Sample Output 1

// Case 1:
// 1/1/1991 to 1/31/2000
// Case 2:
// 1/1/1972 to 2/28/1972
// 3/1/1972
// Case 3:
// No additional quotes are required.

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

map<int, int> date;
vector<int> day;

int next_day(const int &x)
{
    int mday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int yy = x / 10000, mm = x % 10000 / 100, dd = x % 100;
    if ((yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0)
        mday[2] = 29;
    ++dd;
    if (dd > mday[mm])
    {
        dd = 1;
        ++mm;
    }
    if (mm == 13)
    {
        mm = 1;
        ++yy;
    }
    return yy * 10000 + mm * 100 + dd;
}

int prev_day(const int &x)
{
    int mday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int yy = x / 10000, mm = x % 10000 / 100, dd = x % 100;
    if ((yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0)
        mday[2] = 29;
    if (mm == 1 && dd == 1)
    {
        --yy;
        mm = 12;
        dd = 31;
    }
    else
    {
        --dd;
        if (dd < 1)
        {
            --mm;
            dd = mday[mm];
        }
    }
    return yy * 10000 + mm * 100 + dd;
}

void printDate(const int &x)
{
    int yy = x / 10000, mm = x % 10000 / 100, dd = x % 100;
    cout << mm << "/" << dd << "/" << yy;
}

void record(int x)
{
    date[x] = 0;
    date[prev_day(x)] = 0;
    date[next_day(x)] = 0;
}

int main()
{
    int testcase = 0;
    int n, m, nf[128], nl[128], mf[128], ml[128];
    ;

    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        date.clear();
        for (int i = 0; i < n; ++i)
        {
            cin >> nf[i] >> nl[i];
            record(nf[i]);
            record(nl[i]);
        }
        for (int i = 0; i < m; ++i)
        {
            cin >> mf[i] >> ml[i];
            record(mf[i]);
            record(ml[i]);
        }
        int size = 0;
        vector<int> day;
        for (auto i = date.begin(); i != date.end(); ++i)
        {
            i->second = size++;
            day.push_back(i->first);
        }
        vector<int> mark(size, 0);
        for (int i = 0; i < m; ++i)
        {
            int f = date[mf[i]], l = date[ml[i]];
            for (int j = f; j <= l; ++j)
                mark[j] = 1;
        }
        for (int i = 0; i < n; ++i)
        {
            int f = date[nf[i]], l = date[nl[i]];
            for (int j = f; j <= l; ++j)
                mark[j] = 0;
        }
        int t = 0;
        cout << "Case " << ++testcase << ":" << endl;
        for (int i = 0; i < size; ++i)
        {
            if (mark[i] == 1)
            {
                t = 1;
                printDate(day[i]);
                if (mark[i + 1] == 1 && i + 1 < size)
                {
                    cout << " to ";
                    while (mark[i + 1] == 1 && i + 1 < size)
                        ++i;
                    printDate(day[i]);
                }
                cout << endl;
            }
        }
        if (!t)
            cout << "No additional quotes are required." << endl;
    }
}

// #include <iostream>
// #include <string>
// #include <vector>
// #include <map>
// #include <utility>

// using namespace std;

// map<int, int> date;
// vector<int> day;

// int next_day (const int &x)
// {
//     int mday[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
//     int yy = x / 10000, mm = x % 10000 / 100, dd = x % 100;
//     if ((yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0)
//         mday[2] = 29;
//     ++ dd;
//     if (dd > mday[mm])
//     {
//         dd = 1;
//         ++ mm;
//     }
//     if (mm == 13)
//     {
//         mm = 1;
//         ++ yy;
//     }
//     return yy * 10000 + mm * 100 + dd;
// }

// int prev_day (const int &x)
// {
//     int mday[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
//     int yy = x / 10000, mm = x % 10000 / 100, dd = x % 100;
//     if ((yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0)
//         mday[2] = 29;
//     if (mm == 1 && dd == 1)
//     {
//         -- yy;
//         mm = 12;
//         dd = 31;
//     }
//     else
//     {
//         -- dd;
//         if (dd < 1)
//         {
//             -- mm;
//             dd = mday[mm];
//         }
//     }
//     return yy * 10000 + mm * 100 + dd;
// }

// void printDate (const int &x)
// {
//     int yy = x / 10000, mm = x % 10000 / 100, dd = x%100;
//     cout << mm << "/" << dd << "/" << yy;
// }

// void record(int x)
// {
//     date[x] = 0;
//     date[prev_day(x)] = 0;
//     date[next_day(x)] = 0;
// }

// int main()
// {
//     int testcase = 0;
//     int n, m, nf[128], nl[128], mf[128], ml[128];;

//     while (cin >> n >> m)
//     {
//         if (n == 0 && m == 0)
//             break;
//         date.clear();
//         for (int i = 0; i < n; ++ i)
//         {
//             cin >> nf[i] >> nl[i];
//             record(nf[i]);
//             record(nl[i]);
//         }
//         for (int i = 0; i < m; ++ i)
//         {
//             cin >> mf[i] >> ml[i];
//             record(mf[i]);
//             record(ml[i]);
//         }
//         int size = 0;
//         vector<int> day;
//         for (auto i = date.begin(); i != date.end(); ++ i)
//         {
//             i->second = size ++;
//             day.push_back(i->first);
//         }
//         vector<int> mark(size, 0);
//         for (int i = 0; i < m; ++ i)
//         {
//             int f = date[mf[i]], l = date[ml[i]];
//             for (int j = f; j <= l; ++ j)
//                 mark[j] = 1;
//         }
//         for (int i = 0; i < n; ++ i)
//         {
//             int f = date[nf[i]], l = date[nl[i]];
//             for (int j = f; j <= l; ++ j)
//                 mark[j] = 0;
//         }
//         int t = 0;
//         cout << "Case " << ++testcase << ":" << endl;
//         for (int i = 0; i < size; ++ i)
//         {
//             if (mark[i] == 1)
//             {
//                 t = 1;
//                 printDate(day[i]);
//                 if (mark[i + 1] == 1 && i + 1 < size)
//                 {
//                     cout << " to ";
//                     while (mark[i + 1] == 1 && i + 1 < size)
//                         ++ i;
//                     printDate(day[i]);
//                 }
//                 cout << endl;
//             }
//         }
//         if (!t)
//             cout << "No additional quotes are required." << endl;
//     }
// }

// _____________________________________________________________

// #include <stdio.h>
// #include <string.h>
// #include <vector>
// #include <map>
// #include <algorithm>
// using namespace std;

// const int MAXN = 128;
// map<int, int> R;
// int prevDay(int x)
// {
//     int mday[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
//     int yy = x/10000, mm = x%10000/100, dd = x%100;
//     if ((yy%4 == 0 && yy%100 != 0) || yy%400 == 0)
//         mday[2] = 29;
//     if (mm == 1 && dd == 1)
//     {
//         yy--, mm = 12, dd = 31;
//     }
//     else
//     {
//         dd--;
//         if (dd < 1)			mm--, dd = mday[mm];
//     }
//     return yy * 10000 + mm * 100 + dd;
// }

// int nextDay(int x)
// {
//     int mday[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
//     int yy = x/10000, mm = x%10000/100, dd = x%100;
//     if ((yy%4 == 0 && yy%100 != 0) || yy%400 == 0)
//         mday[2] = 29;
//     dd++;
//     if (dd > mday[mm])	dd = 1, mm++;
//     if (mm == 13)		mm = 1, yy++;
//     return yy * 10000 + mm * 100 + dd;
// }
// void record(int x)
// {
//     R[x] = 0, R[nextDay(x)] = 0, R[prevDay(x)] = 0;
// //	printf("-- %d %d %d\n", prevDay(x), x, nextDay(x));
// }
// void printDate(int x)
// {
//     int yy = x/10000, mm = x%10000/100, dd = x%100;
//     printf("%d/%d/%d", mm, dd, yy);
// }
// int main()
// {
//     int cases = 0;
//     int N, M;
//     int aSt[MAXN], aEd[MAXN];
//     int bSt[MAXN], bEd[MAXN];
//     while (scanf("%d %d", &N, &M) == 2)
//     {
//         if (N == 0 && M == 0)
//             break;

//         R.clear();
//         for (int i = 0; i < N; i++)
//         {
//             scanf("%d %d", &aSt[i], &aEd[i]);
//             record(aSt[i]);
//             record(aEd[i]);
//         }
//         for (int i = 0; i < M; i++)
//         {
//             scanf("%d %d", &bSt[i], &bEd[i]);
//             record(bSt[i]);
//             record(bEd[i]);
//         }

//         int size = 0;
//         vector<int> date;
//         for (map<int, int>::iterator it = R.begin();
//                 it != R.end(); it++)
//             it->second = size++, date.push_back(it->first);

//         vector<int> mark(size, 0);
//         for (int i = 0; i < M; i++)
//         {
//             int l = R[bSt[i]], r = R[bEd[i]];
//             for (int j = l; j <= r; j++)
//                 mark[j] = 1;
//         }
//         for (int i = 0; i < N; i++)
//         {
//             int l = R[aSt[i]], r = R[aEd[i]];
//             for (int j = l; j <= r; j++)
//                 mark[j] = 0;
//         }

//         if (cases)
//             puts("");
//         printf("Case %d:\n", ++cases);
//         int has = 0;
//         for (int i = 0; i < mark.size(); i++)
//         {
//             if (mark[i] == 1)
//             {
//                 has = 1;
//                 printf("    ");
//                 printDate(date[i]);
//                 if (i+1 < mark.size() && mark[i+1] == 1)
//                 {
//                     printf(" to ");
//                     while (i+1 < mark.size() && mark[i+1] == 1)
//                         i++;
//                     printDate(date[i]);
//                     printf("\n");
//                 }
//                 else
//                 {
//                     printf("\n");
//                 }
//             }
//         }

//         if (!has)
//             puts("    No additional quotes are required.");
//     }
//     return 0;
// }
