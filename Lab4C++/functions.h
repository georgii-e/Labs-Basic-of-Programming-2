#pragma once
#include <string>
#include "date.h"
using namespace std;

date input();
bool verify_day(int day);
bool verify_month(int month);
bool verify_month(string month);
bool verify_year(int year);
bool verify_date_str(string date);

