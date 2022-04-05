#include "tetr.h"
#include "point.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;





tetrahedron::tetrahedron()
{
    A = generation();
    B = generation();
    C = generation();
    D = generation();
    volume = find_volume();
}
void tetrahedron::getInfo()
{
    cout << endl;
    cout << "-------Tetrahedron-------" << endl;
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
float tetrahedron::getVolume()
{
    return volume;
}
Point tetrahedron::generation()
{
    const int max = 9;
    const int min = -9;
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

