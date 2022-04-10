// Lab4C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "date.h"
#include "functions.h"
using namespace std;


int main()
{
    date D1 = input();
    cout << "\nD1: "; 
    D1.print_info();
    date D2 = input();
    cout << "\nD2: ";
    D2.print_info();
    date D3 = input();
    cout << "\nD3: ";
    D3.print_info();
    cout << "D3 season: ";
    D3.print_season();
    cout << "\nInput amount of days to increase D3: ";
    int days;
    cin >> days;
    D3 += days;
    cout << "\nD3: ";
    D3.print_info();
    cout << "D1-D2= " << D1 - D2 << " days" << endl;

}


