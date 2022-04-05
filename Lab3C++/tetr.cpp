#include "tetr.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int tetrahedron::max = receiveMax();
const int tetrahedron::min = receiveMin();
int tetrahedron::count = 0;

tetrahedron::Point::Point(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
void tetrahedron::Point::show() const
{
    cout << "X=" << setw(3) << x;
    cout << "\tY=" << setw(3) << y;
    cout << "\tZ=" << setw(3) << z << endl;
}
void tetrahedron::Point::setX(int x)
{
    this->x = x;
}
void tetrahedron::Point::setY(int y)
{
    this->y = y;
}
void tetrahedron::Point::setZ(int z)
{
    this->z = z;
}
int tetrahedron::Point::getX() const
{
    return x;
}
int tetrahedron::Point::getY() const
{
    return y;
}
int tetrahedron::Point::getZ() const
{
    return z;
}
tetrahedron::tetrahedron()
{
    A = generation();
    B = generation();
    C = generation();
    D = generation();
    volume = find_volume();
    count++;
    id = count;
}
void tetrahedron::getInfo()
{
    cout << endl;
    cout << "Tetrahedron number: " << getID() << endl;
    cout << "Point A:" << endl;
    A.show();
    cout << "Point B:" << endl;
    B.show();
    cout << "Point C:" << endl;
    C.show();
    cout << "Point D:" << endl;
    D.show();
    printf("Volume: %.2f\n", volume);
}
int tetrahedron::getMax() const
{
    return max;
}
int tetrahedron::getMin() const
{
    return min;
}
int tetrahedron::getID() const
{
    return id;
}
float tetrahedron::getVolume()
{
    return volume;
}
tetrahedron::Point tetrahedron::generation()
{
    Point point{ rand() % (max - min + 1) + min,rand() % (max - min + 1) + min ,rand() % (max - min + 1) + min };
    return point;
}
vector<vector<int>> tetrahedron::matrix_for_volume()
{
    const int size = 3;
    vector < vector <int> > arr(size, vector <int>(size));
    arr[0] = find_vector(A, B);
    arr[1] = find_vector(A, C);
    arr[2] = find_vector(A, D);
    return arr;
}
vector <int> tetrahedron::find_vector(Point start, Point finish)
{
    vector <int> vec;
    vec.push_back(finish.getX() - start.getX());
    vec.push_back(finish.getY() - start.getY());
    vec.push_back(finish.getZ() - start.getZ());
    return vec;
}
float tetrahedron::find_volume()
{
    vector<vector<int>> arr = matrix_for_volume();
    int determinant = arr[0][0] * arr[1][1] * arr[2][2] - arr[0][0] * arr[1][2] * arr[2][1]
        - arr[0][1] * arr[1][0] * arr[2][2] + arr[0][1] * arr[1][2] * arr[2][0]
        + arr[0][2] * arr[1][0] * arr[2][1] - arr[0][2] * arr[1][1] * arr[2][0];
    float volume = abs(determinant) / 6.;
    return volume;
}
void tetrahedron::resetCount()
{
    count = 0;
}
int tetrahedron::receiveMax()
{
    int max = 9;
    cout << "Input max: ";
    cin >> max;
    return max;
}
int tetrahedron::receiveMin()
{
    int min = -9;
    cout << "Input min: ";
    cin >> min;

    return min;
}

tetrahedron* gen_arr(int SIZE)
{
    tetrahedron* p_arr = new tetrahedron[SIZE];
    tetrahedron::resetCount(); //щоб могло бути декілька масивів
    for (int i = 0; i < SIZE; i++)
    {
        p_arr[i] = tetrahedron();
    }
    return p_arr;
}
void remove(tetrahedron* p_arr)
{
    delete[] p_arr;
}
float max(tetrahedron* p_arr, int length, int* id)
{
    float max_value = 0;
    for (int i = 0; i < length; i++)
    {
        if (p_arr[i].getVolume() > max_value)
        {
            max_value = p_arr[i].getVolume();
            *id = p_arr[i].getID();
        }
    }
    printf("\nMaximum volume: %.2f have tetrahedron number: %d\n", max_value, *id);
    return max_value;
}
void output(tetrahedron* p_arr, int length)
{
    for (int i = 0; i < length; i++)
        p_arr[i].getInfo();
}