// POJ 2796

// Description

// Bill is developing a new mathematical theory for human emotions.
// His recent investigations are dedicated to studying how good or bad days influent
// people’s memories about some period of life. A new idea Bill has recently developed
// assigns a non-negative integer value to each day of human life. Bill calls this value the emotional value of the day.
// The greater the emotional value is, the better the day was. Bill suggests that
// the value of some period of human life is proportional to the sum of the emotional values of the days in the given period,
// multiplied by the smallest emotional value of the day in it.
// This schema reflects that good on average period can be greatly spoiled by one very bad day.
// Now Bill is planning to investigate his own life and find the period of his life that had the greatest value. Help him to do so.

// Input
// The input will contain several test cases, each of them as described below.
// Consecutive test cases are separated by a single blank line.
// The first line of the input file contains n — the number of days of Bill’s life
// he is planning to investigate (1 ≤ n ≤ 100000).
// The rest of the file contains n integer numbers a1, a2, . . . , an ranging from 0 to 106 — the emotional values of the days.
// Numbers are separated by spaces and/or line breaks.

// Output
// For each test case, the output must follow the description below. The outputs of two consecutive cases will be separated by a blank line. On the first line of the output file print the greatest value of some period of Bill’s life. On the second line print two numbers l and r such that the period from l-th to r-th day of Bill’s life (inclusive) has the greatest possible value. If there are multiple periods with the greatest possible value, then print any one of them.

// Sample Input 1

// 6
// 3 1 6 4 5 2
// Sample Output 1

// 60
// 3 5

#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int num[n];
        long long sum[n + 1]; // 前 n 個的和
        sum[0] = 0;
        int min;
        long long ans = 0;
        int ll = 1, rr = 1;
        for (int i = 0; i < n; ++i)
        {
            cin >> num[i];

            sum[i + 1] = sum[i] + num[i];
            //cout << sum[i] << endl;
        }
        for (int i = 0; i < n; ++i) // j 加到 i
        {
            for (int j = i; j >= 0; --j)
            {
                if (i == j) // 因為範圍為 1
                    min = num[j];
                else if (num[j] < min)
                    min = num[j];
                //cout << min << endl;
                long long t = min * (sum[i + 1] - sum[j]);
                //cout << j << " " << i << " " << min << " " << sum[i + 1] << " " << sum[j] << endl;
                if (t > ans)
                {
                    //cout << "##";
                    ans = t;
                    rr = i + 1;
                    ll = j + 1;
                }
            }
        }
        cout << ans << endl
             << ll << " " << rr << endl
             << endl;
    }
}

// ___________________________________________________

// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// #include <queue>
// #include <vector>
// #include <cmath>
// #include <string>
// #define LL long long

// using namespace std;
// const int maxn = 1e5 + 5;
// LL sum[maxn];
// int a[maxn];
// int lef[maxn];
// int stack[maxn];

// int main()
// {
//     int n;
//     sum[0] = 0;
//     scanf("%d", &n);
//     for (int i = 1; i <= n; i++)
//     {
//         scanf("%d", &a[i]);
//         sum[i] = sum[i - 1] + a[i];
//     }
//     ++n;
//     a[n] = -1;
//     int top = 0;
//     LL ans = -1;
//     int ll, rr;
//     for (int i = 1; i <= n; i++)
//     {
//         if (top == 0 || a[i] > a[stack[top - 1]])
//         {
//             stack[top++] = i;
//             lef[i] = i;
//             continue;
//         }
//         if (a[i] == a[stack[top - 1]])
//             continue;
//         while (top >= 1 && a[i] < a[stack[top - 1]])
//         {
//             top--;
//             LL tmp = a[stack[top]] * (sum[i - 1] - sum[lef[stack[top]] - 1]);
//             if (tmp > ans)
//             {
//                 ans = tmp;
//                 ll = lef[stack[top]];
//                 rr = i - 1;
//             }
//         }
//         lef[i] = lef[stack[top]];
//         stack[top++] = i;
//     }
//     printf("%lld\n%d %d\n", ans, ll, rr);
//     return 0;
// }

// ________________________________________________________

// #include <stdio.h>
// #include <string.h>
// #define MAX 999999999
// #define MIN -1

// long long table[100001];

// int main()
// {
//     int n;
//     while (scanf("%d", &n) != EOF)
//     {
//         printf("%d", n);
//         memset(table, 0, sizeof(table));
//         for (int i = 0; i < n; i++)
//             scanf("%lld", &table[i]);

//         int start, end;
//         long long result = MIN;
//         for (int range = 0; range < n; range++)
//         {
//             for (int top = 0, bot = top + range; bot < n; top++, bot++)
//             {
//                 long long min = MAX;
//                 long long sum = 0;
//                 for (int i = top; i <= bot; i++)
//                 {
//                     if (min > table[i])
//                         min = table[i];
//                     sum += table[i];
//                 }
//                 if ((min * sum) > result)
//                 {
//                     result = (min * sum);
//                     start = top;
//                     end = bot;
//                 }
//             }
//         }
//         printf("%lld\n%d %d\n\n", result, start + 1, end + 1);
//         n = -1;
//     }

//     return 0;
// }

// _____________________________________________________________________

// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// typedef long long LL;
// const int MAXN = 100050;

// LL a[MAXN], sum[MAXN];
// LL L[MAXN], R[MAXN];
// int main()
// {
//     int n;
//     while (cin >> n)
//     {

//         for (int i = 1; i <= n; i++)
//         {
//             scanf("%lld", &a[i]);
//             sum[i] = sum[i - 1] + a[i];
//             L[i] = R[i] = i;
//         }
//         a[0] = a[n + 1] = -1;
//         for (int i = 1; i <= n; i++)
//         {
//             while (a[i] <= a[L[i] - 1])
//                 L[i] = L[L[i] - 1];
//         }
//         for (int i = n; i >= 1; i--)
//         {
//             while (a[i] <= a[R[i] + 1])
//                 R[i] = R[R[i] + 1];
//         }
//         LL ans = -1, l, r;
//         for (int i = 1; i <= n; i++)
//         {
//             LL T = a[i] * (sum[R[i]] - sum[L[i] - 1]);
//             if (ans < T)
//                 ans = T, l = L[i], r = R[i];
//         }
//         printf("%lld\n%lld %lld\n", ans, l, r);
//     }
// }

// __________________________________________________________________

// #include <iostream>
// #include <cstring>
// #include <cstdio>
// #include <stack>
// using namespace std;
// const int MAX = 100009;
// long long a[MAX];
// long long sum[MAX];
// int n, l[MAX], r[MAX];
// stack<int> st;
// int main()
// {
//     while (scanf("%d", &n) != EOF)
//     {
//         sum[0] = 0;
//         for (int i = 1; i <= n; i++)
//             scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
//         for (int i = 1; i <= n; i++)
//         {
//             while (!st.empty() && a[st.top()] >= a[i])
//             {
//                 r[st.top()] = i - 1; //当前插入a[i]的数值比栈顶元素小，因此栈顶元素向右只能扩展到
//                 //i-1这个位置，因为过了i，最小值就变为a[i]了，所以记录栈顶元素
//                 //向右扩展的边界
//                 st.pop();
//             }

//             if (st.empty())
//                 l[i] = 1; //因为是单调递增栈，因此新插入元素a[i]左端元素是比插入的元素小的
//             else
//                 l[i] = st.top() + 1; //因此他向左扩展的值就是st.top()+1
//             st.push(i);
//         }
//         while (!st.empty()) //将剩余的元素一次弹出，并且每个元素向右都能扩展至最后一个元素
//         {
//             r[st.top()] = n;
//             st.pop();
//         }
//         long long ans = 0;
//         int id = -1;
//         for (int i = 1; i <= n; i++) //枚举求结果
//         {
//             if (ans <= (sum[r[i]] - sum[l[i] - 1]) * a[i])
//             {
//                 ans = (sum[r[i]] - sum[l[i] - 1]) * a[i];
//                 id = i;
//             }
//         }
//         printf("%I64d\n", ans);
//         printf("%d %d\n", l[id], r[id]);
//     }

//     return 0;
// }

// ______________________________________________________________________

// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #define int long long
// using namespace std;
// typedef pair<int, int> P;
// const int MAX = 100010;
// int arr[MAX];
// P que[MAX];
// int sum[MAX];
// int l, r;
// int N;
// void solve()
// {
//     for (int i = 0; i < N; i++)
//     {
//         scanf("%lld", &arr[i]);
//         sum[i + 1] = sum[i] + arr[i];
//     }
//     if (N == 1)
//     {
//         cout << arr[0] * arr[0] << endl
//              << 1 << ' ' << 1 << endl;
//         return;
//     }
//     arr[N] = 0;
//     sum[N + 1] = sum[N];
//     l = 0;
//     r = 1;
//     que[0] = (P){
//         arr[0], 0};
//     int ans = 0;
//     int ansl = 1, ansr = 1;
//     for (int i = 1; i <= N; i++)
//     {
//         while (r > l && que[r - 1].first > arr[i])
//         {
//             r--;
//             if (r - 1 >= 0)
//             {
//                 int na = que[r].first * (sum[i] - sum[que[r - 1].second + 1]);
//                 if (na > ans)
//                 {
//                     ans = na;
//                     ansl = que[r - 1].second + 2;
//                     ansr = i;
//                 }
//             }
//             else
//             {
//                 int na = que[r].first * (sum[i]);
//                 if (na > ans)
//                 {
//                     ans = na;
//                     ansl = 1;
//                     ansr = i;
//                 }
//             }
//         }
//         que[r++] = (P){
//             arr[i], i};
//     }
//     cout << ans << endl;
//     cout << ansl << ' ' << ansr << endl;
// }
// main()
// {
//     while (~scanf("%lld", &N))
//     {
//         solve();
//     }
//     return 0;
// }

// ________________________________________________________________

// #include <cstdio>
// #include <cstring>
// #include <cmath>
// #include <algorithm>
// #define N 300005
// #define LL long long

// using namespace std;

// inline int wread()
// {
//     char c(getchar());
//     int wans(0), flag(1);
//     while (c < '0' || c > '9')
//     {
//         if (c == '-')
//             flag = -1;
//         c = getchar();
//     }
//     while (c >= '0' && c <= '9')
//     {
//         wans = wans * 10 + c - '0';
//         c = getchar();
//     }
//     return wans *= flag;
// }

// int n;
// int sav[N];
// struct node
// {
//     int zhi, pos;
//     node()
//     {
//     }
//     node(int x, int y) : zhi(x), pos(y) {}
// } S[N];
// int top;
// int ml[N], mr[N];
// LL sum[N];

// int main()
// {

//     n = wread();
//     for (int i(1); i <= n; ++i)
//         sav[i] = wread();
//     for (int i(1); i <= n; ++i)
//         sum[i] = sum[i - 1] + (LL)sav[i];
//     S[++top] = node(sav[1], 1);
//     ml[1] = 1;
//     int r(1);
//     while (r != n)
//     {
//         r++;
//         if (sav[r] > S[top].zhi)
//             ml[r] = S[top].pos + 1, S[++top] = node(sav[r], r);
//         else if (sav[r] == S[top].zhi)
//             ml[r] = ml[S[top].pos], S[++top] = node(sav[r], r);
//         else
//         {
//             while (S[top].zhi > sav[r] && top >= 1)
//                 mr[S[top].pos] = r - 1, top--;
//             if (!top)
//                 S[++top] = node(sav[r], r), ml[r] = 1;
//             else
//             {
//                 if (S[top].zhi == sav[r])
//                     ml[r] = ml[S[top].pos], S[++top] = node(sav[r], r);
//                 else
//                     ml[r] = S[top].pos + 1, S[++top] = node(sav[r], r);
//             }
//         }
//     }
//     while (top != 0)
//         mr[S[top].pos] = n, top--;
//     LL ans(-1);
//     int pr(0);
//     for (int i(1); i <= n; ++i)
//         ans < ((LL)sav[i] * (sum[mr[i]] - sum[ml[i] - 1])) ? (pr = i, ans = ((LL)sav[i] * (sum[mr[i]] - sum[ml[i] - 1]))) : ans = ans;
//     printf("%lld\n", ans);
//     printf("%d %d\n", ml[pr], mr[pr]);
//     return 0;
// }
