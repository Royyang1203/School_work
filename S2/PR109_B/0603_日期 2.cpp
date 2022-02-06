// Description

// 將日期的 set functions 改成 cascaded invokable methods。

// Date &Date::set_year(int year)
// {
// }

// Date &Date::set_month(int month)
// {
// }

// Date &Date::set_date(int date)
// {
// }

// int Date::get_year() const
// {
// }

// int Date::get_month() const
// {
// }

// int Date::get_date() const
// {
// }

// void Date::print_date() const
// {
// }

// _____________________________________________________________________________________

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string.h>

class Date
{
private:
    char date[9];

public:
    Date &set_year(int);
    Date &set_month(int);
    Date &set_date(int);
    int get_year() const;
    int get_month() const;
    int get_date() const;
    void print_date() const;
};

// int main(void)
// {
//     Date d;
//     d.set_date(15);
//     d.set_month(5);
//     d.set_year(85);
//     d.print_date();
// }

// void Date::set_year(int year)
// {
//     Date::date[3] = (year % 10) + '0';
//     year /= 10;
//     Date::date[2] = (year % 10) + '0';
//     year /= 10;
//     Date::date[1] = (year % 10) + '0';
//     year /= 10;
//     Date::date[0] = (year % 10) + '0';
// }

// void Date::set_month(int month)
// {
//     if (month / 10)
//         Date::date[4] = '1';
//     else
//         Date::date[4] = '0';
//     date[5] = month % 10 + '0';
// }

// void Date::set_date(int date)
// {
//     if (date / 10 == 1)
//         Date::date[6] = '1';
//     else if (date / 10 == 2)
//         Date::date[6] = '2';
//     else if (date / 10 == 3)
//         Date::date[6] = '3';
//     else
//         Date::date[6] = '0';
//     Date::date[7] = date % 10 + '0';
// }

// int Date::get_year() const
// {
//     char ss[5];
//     for (int i = 0; i < 4; i++)
//         ss[i] = Date::date[i];
//     ss[4] = '\0';
//     return atoi(ss);
// }

// int Date::get_month() const
// {
//     char ss[5];
//     for (int i = 0; i < 2; i++)
//         ss[i] = Date::date[i + 4];
//     ss[2] = '\0';
//     return atoi(ss);
// }

// int Date::get_date() const
// {
//     char ss[5];
//     for (int i = 0; i < 2; i++)
//         ss[i] = Date::date[i + 6];
//     ss[2] = '\0';
//     return atoi(ss);
// }

// void Date::print_date() const
// {
//     switch (get_month())
//     {
//     case 1:
//         std::cout << "Jan";
//         break;
//     case 2:
//         std::cout << "Feb";
//         break;
//     case 3:
//         std::cout << "Mar";
//         break;
//     case 4:
//         std::cout << "Apr";
//         break;
//     case 5:
//         std::cout << "May";
//         break;
//     case 6:
//         std::cout << "Jun";
//         break;
//     case 7:
//         std::cout << "Jul";
//         break;
//     case 8:
//         std::cout << "Aug";
//         break;
//     case 9:
//         std::cout << "Sep";
//         break;
//     case 10:
//         std::cout << "Oct";
//         break;
//     case 11:
//         std::cout << "Nov";
//         break;
//     case 12:
//         std::cout << "Dec";
//         break;
//     }
//     std::cout << " " << Date::get_date() << ", " << Date::get_year() << std::endl;
// } //end

Date &Date::set_year(int year)
{
    date[0] = year / 1000;
    year = year % 1000;
    date[1] = year / 100;
    year = year % 100;
    date[2] = year / 10;
    date[3] = year % 10;
    return *this;
}

Date &Date::set_month(int month)
{
    date[4] = month / 10;
    date[5] = month % 10;
    return *this;
}

Date &Date::set_date(int dat)
{
    date[6] = dat / 10;
    date[7] = dat % 10;
    return *this;
}

int Date::get_year() const
{
    int y = 0;
    for (int i = 0; i < 4; i++)
    {
        y = y * 10 + date[i];
    }
    return y;
}

int Date::get_month() const
{
    int m = 0;
    for (int i = 4; i < 6; i++)
    {
        m = m * 10 + date[i];
    }
    return m;
}

int Date::get_date() const
{
    int d;
    for (int i = 6; i < 8; i++)
    {
        d = d * 10 + date[i];
    }
    return d;
}

void Date::print_date() const
{
    int ye = 0, mo = 0, da = 0;
    for (int i = 0; i < 4; i++)
    {
        ye = ye * 10 + date[i];
    }
    for (int i = 4; i < 6; i++)
    {
        mo = mo * 10 + date[i];
    }
    for (int i = 6; i < 8; i++)
    {
        da = da * 10 + date[i];
    }
    if (mo == 1)
    {
        std::cout << "Jan " << da << ", " << ye << std::endl;
    }
    if (mo == 2)
    {
        std::cout << "Feb " << da << ", " << ye << std::endl;
    }
    if (mo == 3)
    {
        std::cout << "Mar " << da << ", " << ye << std::endl;
    }
    if (mo == 4)
    {
        std::cout << "Apr " << da << ", " << ye << std::endl;
    }
    if (mo == 5)
    {
        std::cout << "May " << da << ", " << ye << std::endl;
    }
    if (mo == 6)
    {
        std::cout << "Jun " << da << ", " << ye << std::endl;
    }
    if (mo == 7)
    {
        std::cout << "Jul " << da << ", " << ye << std::endl;
    }
    if (mo == 8)
    {
        std::cout << "Aug " << da << ", " << ye << std::endl;
    }
    if (mo == 9)
    {
        std::cout << "Sep " << da << ", " << ye << std::endl;
    }
    if (mo == 10)
    {
        std::cout << "Oct " << da << ", " << ye << std::endl;
    }
    if (mo == 11)
    {
        std::cout << "Nov " << da << ", " << ye << std::endl;
    }
    if (mo == 12)
    {
        std::cout << "Dec " << da << ", " << ye << std::endl;
    }
}
