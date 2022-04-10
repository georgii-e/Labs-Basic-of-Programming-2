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
    date(int day = 12, int month = 12, int year = 2012);
    date(string date);
    date(int day, string month, int year);
    int get_day();
    int get_month();
    int get_year();
    void print_info();
    void print_season();
};
date input();

int main()
{
    date D1 = input();
    D1.print_info();
    date D2 = input();
    D2.print_info();
    date D3 = input();
    D3.print_info();
    D3.print_season();
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
    if (date.find('/') != -1)
    {
        int pos_first = date.find('/');
        int pos_last = date.rfind('/');
        day = stoi(date.substr(0, pos_first));
        month = stoi(date.substr(pos_first + 1, pos_last - pos_first));
        year = stoi(date.substr(pos_last + 1, date.length() - pos_last));
    }
    else
    {
        int pos_first = date.find('.');
        int pos_last = date.rfind('.');
        day = stoi(date.substr(0, pos_first));
        month = stoi(date.substr(pos_first + 1, pos_last - pos_first));
        year = stoi(date.substr(pos_last + 1, date.length() - pos_last));
    }
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
    printf("\n%02i.%02i.%04i\n", get_day(), get_month(), get_year());
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


date input()
{
    int mode;
    cout << "\nYou can input date in format" << endl;
    cout << "1:   day=xx, month=xx, year=xxxx" << endl;
    cout << "2:   xx/xx/xxxx (xx.xx.xxxx)" << endl;
    cout << "3:   day=xx, month='*******', year=xxxx" << endl;
    cout << "Choose mode: ";
    cin >> mode;
    int day, month, year;
    string month_str, date_str;
    date D1;
    switch (mode)
    {
    case 1:
    {
        cout << "Input day: ";
        cin >> day;
        cout << "Input month: ";
        cin >> month;
        cout << "Input year: ";
        cin >> year;
        date A(day, month, year);
        return A;
    }
    case 2:
    {
        cout << "Input date: ";
        cin >> date_str;
        date A(date_str);
        return A;
    }
    case 3:
    {
        cout << "Input day: ";
        cin >> day;
        cout << "Input month (word): ";
        cin >> month_str;
        cout << "Input year: ";
        cin >> year;
        date A(day, month_str, year);
        return A;
    }
    default:
        cout << "Incorrect mode" << endl;
        date A;
        return A;
    }
}