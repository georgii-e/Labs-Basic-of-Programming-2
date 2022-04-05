// Lab3C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "point.h"
#include "tetr.h"
#include "func.h"

using namespace std;


int main()
{   setlocale(LC_ALL, "ua");
    srand(time(NULL));
    cout << "Input size of array: ";
    int SIZE, id_of_tetr;
    float volume;
    cin >> SIZE;
    tetrahedron* p_arr = gen_arr(SIZE);
    output(p_arr, SIZE);
    volume = max(p_arr, SIZE, &id_of_tetr);
    remove(p_arr);
}

