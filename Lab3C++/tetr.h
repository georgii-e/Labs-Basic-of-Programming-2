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
    vector<vector<int>> matrix_for_volume(); //��������� ������� � ������� ���������
    vector <int> find_vector(Point start, Point finish); //����� ������� � ���� �����
    float find_volume(); //����� 1/6 ������ ���������� ������� � ������� �� � ������� ��'���
};





