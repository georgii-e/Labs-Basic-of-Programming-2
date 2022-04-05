#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class tetrahedron
{
private:
    const static int max;
    const static int min;
    static int count;
    int id;
    class Point
    {
    private:
        int x, y, z;
    public:
        Point(int x = 0, int y = 0, int z = 0);
        void show() const;
        void setX(int x);
        void setY(int y);
        void setZ(int z);
        int getX() const;
        int getY() const;
        int getZ() const;
    };
    Point A, B, C, D;
    float volume;
public:
    tetrahedron();
    void getInfo();
    int getMax() const;
    int getMin() const;
    int getID() const;
    float getVolume();
    Point generation();
    vector<vector<int>> matrix_for_volume(); //��������� ������� � ������� ���������
    vector <int> find_vector(Point start, Point finish); //����� ������� � ���� �����
    float find_volume(); //����� 1/6 ������ ���������� ������� � ������� �� � ������� ��'���
    static int receiveMax();
    static int receiveMin();
    static void resetCount(); //�������� ��������� ��������� 
};



tetrahedron* gen_arr(int);
void remove(tetrahedron* p_arr);
void output(tetrahedron* p_arr, int length);
float max(tetrahedron* p_arr, int length, int* id); //����� ��������� � ������������ ��'����

