// Description

// Please create a class DateTime.

// Class DateTimeinherits Date in Q38.

// The definition of DateTime as fellow.

// class DateTime : public Date
// {
// public:
//   virtual string toString(); // "mm/dd/yyyy HH:MM:SS"
//   DateTime() : Date()
//   {
//     hour = 0;
//     minute = 0;
//     second = 0;
//   }
//   DateTime(int y, int m, int d, int hh, int mm, int ss) : Date(y, m, d)
//   {
//     hour = hh;
//     minute = mm;
//     second = ss;
//   }
//   void setHour(int h);
//   void setMinute(int m);
//   void setSecond(int s);
//   int getHour() const;
//   int getMinute() const;
//   int getSecond() const;
//   void addHours(int h); // adds the specified number of hours to this instance
//   void addMinutes(int m); // adds the specified number of minutes to this instance
//   void addSeconds(int s); // adds the specified number of seconds to this instance
// private:
//   int hour, minute, second;
// };

#include <string>
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
        string s;
        if (month < 10)
            s += '0';
        s += to_string(month);
        s += ", ";
        if (day < 10)
            s += '0';
        s += to_string(day);
        s += ", ";
        if (year < 10)
            s += "000";
        else if (year < 100)
            s += "00";
        else if (year < 1000)
            s += "0";
        s += to_string(year);
        return s;
    }
    void setDay(int d)
    {
        day = d;
    }
    void setMonth(int m)
    {
        month = m;
    }
    void setYear(int y)
    {
        year = y;
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
        int mday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = 0; i < d; ++i)
        {
            mday[2] = isLeapYear(*this) ? 29 : 28;
            ++day;
            if (mday[month] < day)
            {
                day = 1;
                ++month;
            }
            if (month == 13)
            {
                month = 1;
                ++year;
            }
        }
    }
    void addMonths(int m) // adds the specified number of months to this instance
    {
        int mday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        month += m;
        if (month / 12)
        {
            year += month / 12;
            month %= 12;
        }
        if (mday[month] < day)
        {
            mday[2] = isLeapYear(*this) ? 29 : 28;
            day -= mday[month];
            ++month;
        }
    }
    void addYears(int y) // adds the specified number of years to this instance
    {
        year += y;
        if (!isLeapYear(*this) && day == 29)
        {
            day = 1;
            ++month;
        }
    }
    static bool isLeapYear(const Date &d)
    {
        return !(d.year % 400) || d.year % 100 && !(d.year % 4);
    }

protected:
    int year, month, day;
};

class DateTime : public Date
{
public:
    virtual string toString() // "mm/dd/yyyy HH:MM:SS"
    {
        string s;
        if (month < 10)
            s += '0';
        s += to_string(month);
        s += "/";
        if (day < 10)
            s += '0';
        s += to_string(day);
        s += "/";
        if (year < 10)
            s += "000";
        else if (year < 100)
            s += "00";
        else if (year < 1000)
            s += "0";
        s += to_string(year);
        s += " ";
        if (hour < 10)
            s += '0';
        s += to_string(hour);
        s += ":";
        if (minute < 10)
            s += '0';
        s += to_string(minute);
        s += ":";
        if (second < 10)
            s += '0';
        s += to_string(second);
        return s;
    }
    DateTime() : Date()
    {
        hour = 0;
        minute = 0;
        second = 0;
    }
    DateTime(int y, int m, int d, int hh = 0, int mm = 0, int ss = 0) : Date(y, m, d)
    {
        hour = hh;
        minute = mm;
        second = ss;
    }
    void setHour(int h)
    {
        hour = h;
    }
    void setMinute(int m)
    {
        minute = m;
    }
    void setSecond(int s)
    {
        second = s;
    }
    int getHour() const
    {
        return hour;
    }
    int getMinute() const
    {
        return minute;
    }
    int getSecond() const
    {
        return second;
    }
    void addHours(int h) // adds the specified number of hours to this instance
    {
        hour += h;
        if (hour / 24)
        {
            day += hour / 24;
        }
        hour %= 24;
        this->addDays(0);
    }
    void addMinutes(int m) // adds the specified number of minutes to this instance
    {
        minute += m;
        if (minute / 60)
        {
            hour += minute / 60;
        }
        minute %= 60;
        this->addHours(0);
    }
    void addSeconds(int s) // adds the specified number of seconds to this instance
    {
        second += s;
        if (second / 60)
        {
            minute += second / 60;
        }
        second %= 60;
        this->addMinutes(0);
    }

private:
    int hour, minute, second;
};
int main()
{
    int n;
    DateTime d(2021, 1, 1);
    cin >> n;
    d.addHours(n);
    cout << d.toString() << endl;
    cin >> n;
    d.addMinutes(n);
    cout << d.toString() << endl;
    cin >> n;
    d.addSeconds(n);
    cout << d.toString() << endl;
    return 0;
}

// ____________________________________________________________________________________________

//#include "q38.cpp"
//#include "q40.cpp"

// class DateTime : public Date()
// {
// public:
//     DateTime() : Date()
//     {
//         hour = 0;
//         minute = 0;
//         second = 0;
//     }
//     DateTime(int y, int m, int d, int hh = 0, int mm = 0, int ss = 0) : Date(y, m, d)
//     {
//         hour = hh;
//         minute = mm;
//         second = ss;
//     }
//     virtual string toString()   // "mm/dd/yyyy HH:MM:SS"
//     {
//         ostringstream _s;
//         _s << setw(2) << setfill('0') << getMonth() << "/"
//            << setw(2) << setfill('0') << getDay() << "/"
//            << setw(4) << setfill('0') << getYear() << " "
//            << setw(2) << setfill('0') << hour << ":"
//            << setw(2) << setfill('0') << minute << ":"
//            << setw(2) << setfill('0') << second;

//         return _s.str();
//     }

//     void setHour(int h)
//     {
//         this -> hour = h;
//     }
//     void setMinute(int m)
//     {
//         this -> minute = m;
//     }
//     void setSecond(int s)
//     {
//         this -> second = s;
//     }
//     int getHour() const
//     {
//         return hour;
//     }
//     int getMinute() const
//     {
//         return minute;
//     }
//     int getSecond() const
//     {
//         return second;
//     }
//     void addHours(int h)   // adds the specified number of hours to this instance
//     {
//         hour = hour + h;
//         while (hour >= 24)
//         {
//             hour = hour - 24;
//             Date::addDays(1);
//         }
//     }
//     void addMinutes(int m)   // adds the specified number of minutes to this instance
//     {
//         minute = minute + m;
//         while (minute >= 60)
//         {
//             minute = minute - 60;
//             addHours(1);
//         }
//     }
//     void addSeconds(int s)   // adds the specified number of seconds to this instance
//     {
//         second = second + s;
//         while (second >= 60)
//         {
//             second = second - 60;
//             addMinutes(1);
//         }
//     }

//     TimeSpan operator-(const DateTime &dt) const   // return a TimeSpan object represents a time interval
//     {
//         DateTime d = (*this);
//         TimeSpan *_ts = new TimeSpan();
//         int elapsedSec = 0;
//         while(true)
//         {
//             if(d.getYear() == dt.getYear() && d.getMonth() == dt.getMonth() && d.getDay() == dt.getDay() &&
//                     d.getHour() == dt.getHour() && d.getMinute() == dt.getMinute() && d.getSecond() == dt.getSecond())
//             {
//                 break;
//             }
//             //cout << d.getYear() << " " << d.getMonth() << " " << d.getDay() << " " << d.getHour() <<  " " << d.getMinute() << " " << d.getSecond() <<endl;
//             elapsedSec++;
//             d.addSeconds(1);
//         }
//         _ts->setSec(elapsedSec);

//         return *_ts;
//     }
// private:
//     int hour, minute, second;
// };

// // for Q40
// int main()
// {
//     int y, m, d, hh, mm, ss;
//     cin>>y>>m>>d>>hh>>mm>>ss;
//     DateTime d1(y, m, d, hh, mm, ss);
//     cin>>y>>m>>d>>hh>>mm>>ss;
//     DateTime d2(y, m, d, hh, mm, ss);
//     cout<<(d1 - d2).toTotalSeconds();
//     return 0;
// }

// // ==========

// /* for Q39
// int main() {
//   int n;
//   DateTime d(2021, 1, 1);
//   cin>>n;
//   d.addHours(n);
//   cout<<d.toString()<<endl;
//   cin>>n;
//   d.addMinutes(n);
//   cout<<d.toString()<<endl;
//   cin>>n;
//   d.addSeconds(n);
//   cout<<d.toString()<<endl;
//   return 0;
// }
// */
