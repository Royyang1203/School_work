// Description

// Finish the following definition

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
// class TimeSpan
// {
// public:
//   TimeSpan();
//   TimeSpan(int d, int hh, int mm, int ss);
//   int toTotalDays();
//   int toTotalHours();
//   int toTotalMinutes();
//   int toTotalSeconds();
//   string toString();
// private:
//   int day, hour, minute, second;
// };
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
//   DateTime operator-(const DateTime &dt) const; // return a TimeSpan object represents a time interval
// private:
//   int hour, minute, second;
// };

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class TimeSpan;
class DateTime;
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
    virtual string toString() // "mm/dd/yyyy HH:MM:SS"
    {
        ostringstream _s;
        _s << setw(2) << setfill('0') << getMonth() << "/"
           << setw(2) << setfill('0') << getDay() << "/"
           << setw(4) << setfill('0') << getYear();

        return _s.str();
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

class TimeSpan
{
public:
    friend DateTime;
    TimeSpan() = default;
    TimeSpan(int d, int hh, int mm, int ss) : day(d), hour(hh), minute(mm), second(ss) {}
    int toTotalDays()
    {
        return day;
    }
    int toTotalHours()
    {
        return day * 24 + hour;
    }
    int toTotalMinutes()
    {
        return toTotalHours() * 60 + minute;
    }
    int toTotalSeconds()
    {
        return toTotalMinutes() * 60 + second;
    }
    string toString() // "mm/dd/yyyy HH:MM:SS"
    {
        ostringstream _s;
        _s << setw(2) << setfill('0') << day << " "
           << setw(2) << setfill('0') << hour << ":"
           << setw(2) << setfill('0') << minute << ":"
           << setw(2) << setfill('0') << second;
        return _s.str();
    }

private:
    int day = 0, hour = 0, minute = 0, second = 0;
};

class DateTime : public Date
{
public:
    virtual string toString() // "mm/dd/yyyy HH:MM:SS"
    {
        ostringstream _s;
        _s << setw(2) << setfill('0') << getMonth() << "/"
           << setw(2) << setfill('0') << getDay() << "/"
           << setw(4) << setfill('0') << getYear() << " "
           << setw(2) << setfill('0') << hour << ":"
           << setw(2) << setfill('0') << minute << ":"
           << setw(2) << setfill('0') << second;

        return _s.str();
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
    DateTime(DateTime const &that)
    {
        *this = that;
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
    bool is_same_day(const DateTime &that) const
    {
        return this->year == that.year && this->month == that.month && this->day == that.day;
    }
    bool is_larger(const DateTime &that) const
    {
        if (year != that.year)
            return year > that.year;
        if (month != that.month)
            return month > that.month;
        if (day != that.day)
            return day > that.day;
        if (hour != that.hour)
            return hour > that.hour;
        if (minute != that.minute)
            return minute > that.minute;
        if (second != that.second)
            return second > that.second;
        return true;
    }
    TimeSpan operator-(const DateTime &dt) const // return a TimeSpan object represents a time interval
    {
        if (!is_larger(dt))
        {
            //cout << "##";
            return dt - *this;
        }
        DateTime t(dt);
        TimeSpan a;
        for (int i = dt.year; i < this->year; ++i)
        {
            //cout << i << "year" << endl;
            a.day += (isLeapYear(Date(i, 0, 0))) ? 366 : 365;
            //cout << a.day << endl;
        }
        a.day -= dt.days_through_Date();
        a.day += days_through_Date();
        a.second = this->second - dt.second;
        a.minute = this->minute - dt.minute;
        a.hour = this->hour - dt.hour;
        if (a.second < 0)
        {
            a.second += 60;
            --a.minute;
        }
        if (a.minute < 0)
        {
            a.minute += 60;
            --a.hour;
        }
        if (a.hour < 0)
        {
            a.hour += 24;
            --a.day;
        }
        return a;
    }
    int days_through_Date() const
    {
        int sum = 0;
        int mday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeapYear(*this))
            mday[2] = 29;
        for (int i = 0; i < this->month; ++i)
            sum += mday[i];
        //cout << sum +day << endl;
        return sum + day;
    }

private:
    int hour, minute, second;
};

int main()
{
    int y, m, d, hh, mm, ss;
    cin >> y >> m >> d >> hh >> mm >> ss;
    DateTime d1(y, m, d, hh, mm, ss);
    cin >> y >> m >> d >> hh >> mm >> ss;
    DateTime d2(y, m, d, hh, mm, ss);
    cout << (d1 - d2).toTotalSeconds();
    /*
    cout << endl;
    TimeSpan dt(d1 - d2);
    cout << dt.toString() << endl;
    */
    return 0;
}