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
    date();
    date(int day, int month, int year);
    date(string date);
};

int main()
{
    date p("12/12/1222");
}

date::date()
{
    cout << "default constructor" << endl;
    this->day = 12;
    this->month = 12;
    this->year = 2012;
}
date::date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}
date::date(string date)
{
    int pos_first = date.find('/');
    int pos_last = date.rfind('/');
    day = stoi(date.substr(0, pos_first));
    month = stoi(date.substr(pos_first+1, pos_last-pos_first));
    year = stoi(date.substr(pos_last+1, date.length()- pos_last));
}
//verify