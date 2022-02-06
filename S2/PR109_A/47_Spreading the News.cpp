// UVa 924

// Description

// In a large organization, everyone knows a lot of colleagues.
// However, friendship relations are kept with only a few of them, to whom news are told.
// Suppose that whenever an employee knows of a piece of news, he tells it to all his friends on the following day.
// So, on the first day, the source of the information tells it to his friends; on the second day,
// the source’s friends tell it to their friends; on the third day, the friends of the source’s friends’ tell it to their friends;
// and so on.The goal is to determine:• the maximum daily boom size,
// which is the largest number of employees that, on a single day,hear the piece of news for the first time;
// and• the first boom day, which is the first day on which the maximum daily boom size occurs.
// Write a program that, given the friendship relations between the employees and the source of a piece of news,
// computes the maximum daily boom size and the first boom day of that information spreading process.

// Input
// The first line of the input contains the number E of employees (1 ≤ E ≤ 2500).
// Employees are numbered from 0 to E − 1.Each of the following E lines specifies
// the set of friends of an employee’s (from employee 0 to employee E − 1).
// A set of friends contains the number of friends N (0 ≤ N < 15), followed by N distinct integers representing the employee’s friends.
// All integers are separated by a single space.The next line contains an integer T (1 ≤ T < 60),
// which is the number of test cases.Each of the following T lines contains an employee,
// which represents the (unique) source of the piece of news in the test case.

// Output
// The output consists of T lines, one for each test case.If no employee (but the source) hears the piece of news,
// the output line contains the integer ‘0’.Otherwise,
// the output line contains two integers, M and D, separated by a single space,
// where M is the maximum daily boom size and D is the first boom day.

// Sample Input 1

// 6
// 2 1 2
// 2 3 4
// 3 0 4 5
// 1 4
// 0
// 2 0 2
// 3
// 0
// 4
// 5
// Sample Output 1

// 3 2
// 0
// 2 1

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int e; // 有m個人
    cin >> e;
    vector<vector<int>> v(e);
    //v.assign(e, vector<int>());

    // 輸入每個人的傳播
    for (int i = 0; i < e; ++i)
    {
        int n; // 告訴幾個人
        cin >> n;
        while (n--)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n; // 第幾個人得到訊息
        cin >> n;

        bool knew[e] = {false};
        knew[n] = true;
        queue<int> q;
        q.push(n);
        int day = 0, max = 0, mday = 0;
        while (!q.empty())
        {
            int cnt = 0;
            ++day;
            int m = q.size();
            while (m--)
            {
                int now = q.front(); // 第 now 個人的資訊
                q.pop();

                for (int p : v[now])
                {
                    if (knew[p]) // 這個人已知道
                        continue;
                    q.push(p);
                    knew[p] = true;
                    ++cnt;
                }
            }
            if (cnt > max)
            {
                max = cnt;
                mday = day;
            }
        }
        if (max == 0)
            cout << '0' << endl;
        else
            cout << max << " " << mday << endl;
    }
}