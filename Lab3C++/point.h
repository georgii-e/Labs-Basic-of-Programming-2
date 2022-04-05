#pragma once
using namespace std;
class tetrahedron;
class Point
{
    friend tetrahedron;
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


