// Description

// Please create a class Date represent a date.

// The definition of the class is as fellow.

// class Date
// {
// public:
//   Date()
//   {
//     year = 1;
//     month = 1;
//     day = 1;
//   }
//   Date(int y, int m, int d)
//   {
//     year = y;
//     month = m;
//     day = d;
//   }
//   virtual string toString(); // "mm, dd, yyyy"
//   void setDay(int d);
//   void setMonth(int m);
//   void setYear(int y);
//   int getDay() const;
//   int getMonth() const;
//   int getYear() const;
//   void addDays(int d); // adds the specified number of days to this instance
//   void addMonths(int m); // adds the specified number of months to this instance
//   void addYears(int y); // adds the specified number of years to this instance
//   static bool isLeapYear(const Date &d);
// private:
//   int year, month, day;
// };

// Input
// NONE

// Output
// NONE

// Sample Input 1

// 30 1 1
// Sample Output 1

// 01, 31, 2021
// 03, 03, 2021
// 03, 03, 2022

#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;
class Date
{
public:
    Date()
    {
        year = 1;
        month = 1;
        day = 1;
    }
    Date(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    virtual string toString() // "mm, dd, yyyy"
    {
        ostringstream _s;
        _s << setw(2) << setfill('0') << month << ", "
           << setw(2) << setfill('0') << day << ", "
           << setw(4) << setfill('0') << year;
        string s(_s.str());
        return s;
    }

    void setDay(int d)
    {
        this->day = d;
    }
    void setMonth(int m)
    {
        this->month = m;
    }
    void setYear(int y)
    {
        this->year = y;
    }
    int getDay() const
    {
        return day;
    }
    int getMonth() const
    {
        return month;
    }
    int getYear() const
    {
        return year;
    }
    void addDays(int d) // adds the specified number of days to this instance
    {
        day = day + d;
        while (day > getDays(month))
        {
            day = day - getDays(month);
            addMonths(1);
        }
    }
    void addMonths(int m) // adds the specified number of months to this instance
    {
        month = month + m;
        while (month > 12)
        {
            month = month - 12;
            addYears(1);
        }
    }
    void addYears(int y) // adds the specified number of years to this instance
    {
        year = year + y;
    }
    static bool isLeapYear(const Date &d)
    {
        return (d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0;
    }

private:
    int days[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, month, day;

    int getDays(int month)
    {
        return month == 2 ? isLeapYear(*this) ? 29 : 28 : days[month];
    }
};

int main()
{
    int n;
    Date d(2021, 1, 1);
    cin >> n;
    d.addDays(n);
    cout << d.toString() << endl;
    cin >> n;
    d.addMonths(n);
    cout << d.toString() << endl;
    cin >> n;
    d.addYears(n);
    cout << d.toString() << endl;
    return 0;
}

// __________________________________________________________________________________

// #include <string>
// #include <iostream>
// using namespace std;

// class Date
// {
// public:
//     Date()
//     {
//         year = 1;
//         month = 1;
//         day = 1;
//     }
//     Date(int y, int m, int d)
//     {
//         year = y;
//         month = m;
//         day = d;
//     }
//     virtual string toString() // "mm, dd, yyyy"
//     {
//         string s;
//         if (month < 10)
//             s += '0';
//         s += to_string(month);
//         s += ", ";
//         if (day < 10)
//             s += '0';
//         s += to_string(day);
//         s += ", ";
//         if (year < 10)
//             s += "000";
//         else if (year < 100)
//             s += "00";
//         else if (year < 1000)
//             s += "0";
//         s += to_string(year);
//         return s;
//     }
//     void setDay(int d)
//     {
//         day = d;
//     }
//     void setMonth(int m)
//     {
//         month = m;
//     }
//     void setYear(int y)
//     {
//         year = y;
//     }
//     int getDay() const
//     {
//         return day;
//     }
//     int getMonth() const
//     {
//         return month;
//     }
//     int getYear() const
//     {
//         return year;
//     }
//     void addDays(int d) // adds the specified number of days to this instance
//     {
//         int mday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//         for (int i = 0; i < d; ++i)
//         {
//             mday[2] = isLeapYear(*this) ? 29 : 28;
//             ++day;
//             if (mday[month] < day)
//             {
//                 day = 1;
//                 ++month;
//             }
//             if (month == 13)
//             {
//                 month = 1;
//                 ++year;
//             }
//         }
//     }
//     void addMonths(int m) // adds the specified number of months to this instance
//     {
//         int mday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//         month += m;
//         if (month / 12)
//         {
//             year += month / 12;
//             month %= 12;
//         }
//         if (mday[month] < day)
//         {
//             mday[2] = isLeapYear(*this) ? 29 : 28;
//             day -= mday[month];
//             ++month;
//         }
//     }
//     void addYears(int y) // adds the specified number of years to this instance
//     {
//         year += y;
//         if (!isLeapYear(*this) && day == 29)
//         {
//             day = 1;
//             ++month;
//         }
//     }
//     static bool isLeapYear(const Date &d)
//     {
//         return !(d.year % 400) || d.year % 100 && !(d.year % 4);
//     }

// private:
//     int year, month, day;
// };
// int main()
// {
//     int n;
//     Date d(2021, 1, 1);
//     cin >> n;
//     d.addDays(n);
//     cout << d.toString() << endl;
//     cin >> n;
//     d.addMonths(n);
//     cout << d.toString() << endl;
//     cin >> n;
//     d.addYears(n);
//     cout << d.toString() << endl;
//     return 0;
// }