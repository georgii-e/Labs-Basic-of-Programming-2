#pragma once
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
    int julian_day(int day, int month, int year); //amount of days from January 1, 4713 B.C. uh
    date operator += (int value);
    int operator - (const date& other);
};

