#pragma once
#include "point.h"
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


class tetrahedron
{
private:
    Point A, B, C, D;
    float volume;
public:
    tetrahedron();
    void getInfo();
    float getVolume();
    Point generation();
    vector<vector<int>> matrix_for_volume(); //створення матриці з векторів тетраедра
    vector <int> find_vector(Point start, Point finish); //пошук вектора з двох точок
    float find_volume(); //пошук 1/6 модуля визначника матриці з векторів що і дорівнює об'єму
};





