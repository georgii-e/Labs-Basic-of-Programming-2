// Lab4C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class date 
{
private:
    int day, month, year;
public:
    date(int day=12, int month=12, int year=2012);
    date(string date);
    date(int day, string month, int year);
    int get_day();
    int get_month();
    int get_year();
    void print_info();
};

int main()
{
    date p("12/12/1222");
    date e(9, "april", 2004);
    e.print_info();


}

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
}
date::date(string date)
{
    int pos_first = date.find('/');
    int pos_last = date.rfind('/');
    day = stoi(date.substr(0, pos_first));
    month = stoi(date.substr(pos_first+1, pos_last-pos_first));
    year = stoi(date.substr(pos_last+1, date.length()- pos_last));
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
    printf("%02i.%02i.%04i", get_day(), get_month(), get_year());
}
//verify