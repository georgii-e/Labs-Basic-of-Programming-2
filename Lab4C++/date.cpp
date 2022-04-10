#include "date.h"
#include <iostream>
#include <iomanip>
date::date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}
date::date(int day, string month, int year)
{
    this->day = day;
    this->year = year;
    for (auto& c : month)
    {
        c = tolower(c);
    }
    if (month == "january")
        this->month = 1;
    else if (month == "february")
        this->month = 2;
    else if (month == "march")
        this->month = 3;
    else if (month == "april")
        this->month = 4;
    else if (month == "may")
        this->month = 5;
    else if (month == "june")
        this->month = 6;
    else if (month == "july")
        this->month = 7;
    else if (month == "august")
        this->month = 8;
    else if (month == "september")
        this->month = 9;
    else if (month == "october")
        this->month = 10;
    else if (month == "november")
        this->month = 11;
    else if (month == "december")
        this->month = 12;
    else
        this->month = 12;
}
date::date(string date)
{
    int pos_first = date.find('/');
    int pos_last = date.rfind('/');
    day = stoi(date.substr(0, pos_first));
    month = stoi(date.substr(pos_first + 1, pos_last - pos_first));
    year = stoi(date.substr(pos_last + 1, date.length() - pos_last));
}
int date::get_day()
{
    return day;
}
int date::get_month()
{
    return month;
}
int date::get_year()
{
    return year;
}
void date::print_info()
{
    printf("%02i.%02i.%04i\n\n", get_day(), get_month(), get_year());
}
void date::print_season()
{
    if (month <= 2 or month == 12)
        cout << "It's winter now" << endl;
    else if (month >= 3 or month <= 5)
        cout << "It's spring now" << endl;
    else if (month >= 6 or month <= 9)
        cout << "It's summer now" << endl;
    else
        cout << "It's autumn now" << endl;
}
int date::julian_day(int day, int month, int year)
{
    //https://ru.wikipedia.org/wiki/%D0%AE%D0%BB%D0%B8%D0%B0%D0%BD%D1%81%D0%BA%D0%B0%D1%8F_%D0%B4%D0%B0%D1%82%D0%B0
    int a = ((14 - month) / 12);
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    int julian_day = day + int((153 * m + 2) / 5) + 365 * y + int(y / 4) - int(y / 100) + int(y / 400) - 32045;
    return julian_day;
}
date date::operator += (int value)
{
    int days_per_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    for (int i = 0; i < value; i++)
    {
        day++;
        if (day > days_per_month[month - 1])
        {
            day = 1;
            month++;
            if (month == 13)
            {
                month = 1;
                year++;
            }
        }
    }
    return *this;
}
int date::operator - (const date& other)
{
    return julian_day(day, month, year) - julian_day(other.day, other.month, other.year);
}
