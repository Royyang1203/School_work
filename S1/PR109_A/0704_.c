// Description

// An electoral system is a set of rules that determine how elections and referendums are conducted and how their results are determined. For a single-winner election, we have two different electoral systems:

// - majoritarian system: candidate have to receive a majority (more than half) of the votes to be elected.
// - plurality system: candidate with the highest number of votes wins, with no requirement to get a majority of votes.
// Please write a program to detect which candidate wins the election.

// 選舉系統指的是一組規範一場選舉如何進行投票和如何決定勝出者的規則。對單一勝選者來說，我們有以下兩種系統：

// - 絕對多數系統：由獲得絕對多數(過半)者勝出。
// - 相對多數系統：由獲得票最高者勝出，不需要是絕對多數。
// 請寫個程式來找出勝選者。

// Input
// Input file consists several test cases.Each test case consists 2 lines of data. First line is 2 integers n and m, shows the number of candidates and the number of votes. Second line consists m integers, shows the votes. Candidates are numbered by integers [1, n]. 1 < n < 200. 1 <= m <= 1000000. n = m = 0 shows end of test cases.

// 輸入包含多組測資。每組測資包含兩行資料。第一行是 2 個整數 n 和 m, 代表候選人數和選票數。第二行是 m 個整數，代表選票。候選人以 [1, n] 的整數編號。1 < n < 200。1 <= m <= 1000000。n = m = 0 表示測試結束。

// Output
// Output of each test case occupy one line.If there are no single-winner, output "No winner". If the winner may win a majoritarian election, output "Majoritarian winner" and the winner. If the winner can only win a plurality election, output "Plurality winner" and the winner.

// 每組測資的輸出佔據一行。若無法決定單一勝出者，輸出 "No winner".若該勝出者能在絕對多數系統中勝選，輸出 "Majoritarian winner" 和勝者。若該勝出者只在相對多數系統中勝選，輸出 "Plurality winner" 和勝者。

// Sample Input 1

// 3 7
// 1 1 1 3 1 2 3
// 2 4
// 1 1 2 2
// 3 6
// 1 1 1 2 2 3
// 2 6
// 1 2 2 3 3 3
// 0 0
// Sample Output 1

// Majoritarian winner 1
// No winner
// Plurality winner 1
// Plurality winner 2

#include <stdio.h>

int main(void)
{
    int n, m, a, b;
    while (scanf("%d%d", &n, &m) != EOF && n != 0 && m != 0)
    {
        int win = 0, arr[300] = {0};
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &a);
            if (a <= n)
                arr[a]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] > arr[arr[0]])
            {
                win = 1;
                arr[0] = i;
            }
            else if (arr[i] == arr[arr[0]])
                win = 0;
        }
        if (win == 0)
            printf("No winner\n");
        else if (arr[arr[0]] > m / 2)
            printf("Majoritarian winner %d\n", arr[0]);
        else
            printf("Plurality winner %d\n", arr[0]);
    }
}

// #include <stdio.h>

// int main()
// {
//     int n, m, v, w, q;
//     while (scanf("%d%d", &n, &m) != EOF && n != 0 && m != 0)
//     {
//         int a[n + 1];
//         q = 1;
//         for (int i = 0; i < n + 1; i++)
//             a[i] = 0;
//         for (int i = 1; i <= m; i++)
//         {
//             scanf("%d", &v);
//             if (v <= n)
//             {
//                 a[v]++;
//             }
//         }
//         if (a[1] > 0)
//         {
//             q = 0;
//             w = 1;
//         }
//         for (int i = 1; i < n; i++)
//         {
//             if (a[w] < a[i + 1])
//             {
//                 w = i + 1;
//                 q = 0;
//             }
//             else if (w == i && a[i] == a[i + 1])
//                 q = 1;
//         }

//         if (q)
//             printf("No winner\n");
//         else if (a[w] > m / 2)
//             printf("Majoritarian winner %d\n", w);
//         else
//             printf("Plurality winner %d\n", w);
//     }
//     return 0;
// }