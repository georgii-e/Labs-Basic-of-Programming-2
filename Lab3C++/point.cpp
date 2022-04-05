#include "point.h"
#include <iomanip>
#include <iostream>
using namespace std;


Point::Point(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
void Point::show() const
{
    std::cout << "X=" << setw(3) << x;
    cout << "\tY=" << setw(3) << y;
    cout << "\tZ=" << setw(3) << z << endl;
}
void Point::setX(int x)
{
    this->x = x;
}
void Point::setY(int y)
{
    this->y = y;
}
void Point::setZ(int z)
{
    this->z = z;
}
int Point::getX() const
{
    return x;
}
int Point::getY() const
{
    return y;
}
int Point::getZ() const
{
    return z;
}
