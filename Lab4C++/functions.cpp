#include "functions.h"
#include <iostream>
#include <iomanip>
#include <vector>


date input()
{
    int mode;
    cout << "You can input date in format" << endl;
    cout << "1:   day=xx, month=xx, year=xxxx" << endl;
    cout << "2:   xx/xx/xxxx" << endl;
    cout << "3:   day=xx, month='*******', year=xxxx" << endl;
    cout << "\nChoose mode: ";
    cin >> mode;
    int day, month, year;
    string month_str, date_str;
    date D1;
    switch (mode)
    {
    case 1:
    {
        cout << "\nInput day: ";
        cin >> day;
        while (!verify_day(day))
        {
            cout << "\nInput day: ";
            cin >> day;
        }
        cout << "Input month: ";
        cin >> month;
        while (!verify_month(month))
        {
            cout << "\nInput month: ";
            cin >> month;
        }
        cout << "Input year: ";
        cin >> year;
        while (!verify_year(year))
        {
            cout << "\nInput year: ";
            cin >> year;
        }
        date A(day, month, year);
        return A;
    }
    case 2:
    {
        cout << "\nInput date: ";
        cin >> date_str;
        while (!verify_date_str(date_str))
        {
            cout << "\nInput date: ";
            cin >> date_str;
        }
        date A(date_str);
        return A;
    }
    case 3:
    {
        cout << "\nInput day: ";
        cin >> day;
        while (!verify_day(day))
        {
            cout << "\nInput day: ";
            cin >> day;
        }
        cout << "Input month (word): ";
        cin >> month_str;
        while (!verify_month(month_str))
        {
            cout << "\nInput month: ";
            cin >> month_str;
        }
        cout << "Input year: ";
        cin >> year;
        while (!verify_year(year))
        {
            cout << "\nInput year: ";
            cin >> year;
        }
        date A(day, month_str, year);
        return A;
    }
    default:
        cout << "Incorrect mode" << endl;
        date A;
        return A;
    }
}
bool verify_day(int day)
{
    if (day < 0 || day>31)
    {
        cout << "Incorrect day" << endl;
        return false;
    }
    return true;
}
bool verify_month(int month)
{
    if (month < 0 || month > 12)
    {
        cout << "Incorrect month" << endl;
        return false;
    }
    return true;
}
bool verify_month(string month)
{
    vector <string> months = { "january","february","march","april" ,"may" ,"june",
        "july","august","september","october" ,"november","december" };
    for (auto& c : month)
    {
        c = tolower(c);
    }
    if (find(months.begin(), months.end(), month) == months.end())
    {
        cout << "Incorrect month" << endl;
        return false;
    }
    return true;
}
bool verify_year(int year)
{
    if (year < 0)
    {
        cout << "Incorrect year" << endl;
        return false;
    }
    return true;
}
bool verify_date_str(string date)
{
    try
    {
        int pos_first = date.find('/');
        int pos_last = date.rfind('/');
        int day;
        int month;
        int year;
        day = stoi(date.substr(0, pos_first));
        if (verify_day(day))
        {
            month = stoi(date.substr(pos_first + 1, pos_last - pos_first));
            if (verify_month(month))
            {
                year = stoi(date.substr(pos_last + 1, date.length() - pos_last));
                if (verify_year(year))
                    return true;
            }
        }
        return false;
    }
    catch (const std::exception&)
    {
        cout << "Incorrect format of date" << endl;
        return false;
    }
}