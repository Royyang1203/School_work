// UVa 1727

// Description

// The contestants probably don’t know how eagerly problem setters
// (The people who prepare problems for a programmingcontest)
// wait for the weekend to make problems that wouldterrorize contestants :-).
// So before a month begins, someproblem-setters try to calculate the number of weekend
// daysin that month and plans accordingly. Can you help them tocalculate this?

// There are seven days in a week namely Sunday (SUN),Monday (MON), Tuesday (TUE),
// Wednesday (WED), Thursday (THU), Friday (FRI) and Saturday (SAT).
// There are twelve months in a year, January (JAN), February (FEB), March (MAR),April (APR),
// May (MAY), June (JUN), July (JUL), August (AUG), September (SEP), October(OCT),
// November (NOV) and December (DEC). These months have 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 and 31 days respectively.
// In leap years, the month of February has 29 days. In the bracket thethree letter code for each month and each day are shown.
// Unlike many countries of the world Friday(FRI) and Saturday (SAT) are considered weekend days in Bangladesh.
// Given a month and the nameof the first day of that month, you will have to find out the total no of weekend days in that month.

// Input
// First line contains an integer T (T ≤ 100) which denotes the number of test cases.
// The input for each set is given in a single line. This line contains two strings MT H and DAY ,
// here MT H is the three digit code of the month and DAY is the three digit code for the name of the first day of that Month.

// Output
// For each line of input produce one line of output. It contains a single integer
// which denotes the number of weekend days (Fridays and Saturdays) in that month.
// You must do your calculation assuming that the year is not a leap leap year.

// Sample Input 1

// 3
// JAN SUN
// FEB SUN
// OCT THU
// Sample Output 1

// 8
// 8
// 10

#include <string>
#include <iostream>

using namespace std;
int main()
{
    long long int s, t, i, j, k;
    string m, day;
    cin >> t;
    for (i = 1; i <= t; ++i)
    {
        cin >> m >> day;
        if (m == "APR" || m == "JUN" || m == "SEP" || m == "NOV")
        {
            if (day == "FRI")
            {
                cout << 10 << endl;
            }
            else if (day == "THU" || day == "SAT")
            {
                cout << 9 << endl;
            }
            else
            {
                cout << 8 << endl;
            }
        }
        else if (m == "FEB")
        {
            cout << 8 << endl;
        }
        else
        {
            if (day == "THU" || day == "FRI")
            {
                cout << 10 << endl;
            }
            else if (day == "WED" || day == "SAT")
            {
                cout << 9 << endl;
            }
            else
            {
                cout << 8 << endl;
            }
        }
    }
    return 0;
}