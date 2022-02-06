// Description

// 現有一類別class Date，可用來處理日期

class Date
{
private:
    char date[9];

public:
    void set_year(int);
    void set_month(int);
    void set_date(int);
    int get_year() const;
    int get_month() const;
    int get_date() const;
    void print_date() const;
};
// 日期資料皆存放於char date[]中，其中：

// date[0~3] 用來保存年
// date[4~5] 用來保存月
// date[6~7] 用來保存日請實作 get/set functions 來存取 年/月/日
// 並實作 print_date() 來將日期以月名 日, 年<換行>的格式輸出。月名的型式為三碼英文縮寫：Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec。

#include <iostream>
void Date::set_year(int year)
{
    Date::date[3] = (year % 10) + '0';
    year /= 10;
    Date::date[2] = (year % 10) + '0';
    year /= 10;
    Date::date[1] = (year % 10) + '0';
    year /= 10;
    Date::date[0] = (year % 10) + '0';
}

void Date::set_month(int month)
{
    if (month / 10)
        Date::date[4] = '1';
    else
        Date::date[4] = '0';
    date[5] = month % 10 + '0';
}

void Date::set_date(int date)
{
    if (date / 10 == 1)
        Date::date[6] = '1';
    else if (date / 10 == 2)
        Date::date[6] = '2';
    else if (date / 10 == 3)
        Date::date[6] = '3';
    else
        Date::date[6] = '0';
    Date::date[7] = date % 10 + '0';
}

int Date::get_year() const
{
    char ss[5];
    for (int i = 0; i < 4; i++)
        ss[i] = Date::date[i];
    ss[4] = '\0';
    return atoi(ss);
}

int Date::get_month() const
{
    char ss[5];
    for (int i = 0; i < 2; i++)
        ss[i] = Date::date[i + 4];
    ss[2] = '\0';
    return atoi(ss);
}

int Date::get_date() const
{
    char ss[5];
    for (int i = 0; i < 2; i++)
        ss[i] = Date::date[i + 6];
    ss[2] = '\0';
    return atoi(ss);
}

void Date::print_date() const
{
    switch (get_month())
    {
    case 1:
        std::cout << "Jan";
        break;
    case 2:
        std::cout << "Feb";
        break;
    case 3:
        std::cout << "Mar";
        break;
    case 4:
        std::cout << "Apr";
        break;
    case 5:
        std::cout << "May";
        break;
    case 6:
        std::cout << "Jun";
        break;
    case 7:
        std::cout << "Jul";
        break;
    case 8:
        std::cout << "Aug";
        break;
    case 9:
        std::cout << "Sep";
        break;
    case 10:
        std::cout << "Oct";
        break;
    case 11:
        std::cout << "Nov";
        break;
    case 12:
        std::cout << "Dec";
        break;
    }
    std::cout << " " << Date::get_date() << ", " << Date::get_year() << std::endl;
}