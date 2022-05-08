#include "TVector3.h"
#include <math.h>

TVector3::TVector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
float TVector3::get_coord(char coord)
{
	switch (coord)
	{
	case 'x':
		return x;
		break;
	case 'y':
		return y;
		break;
	case 'z':
		return z;
		break;
	}
}
float TVector3::get_length()
{
	return sqrt(x * x + y * y + z * z);
}
float TVector3::scalar(TVector& other)
{
	return x * other.get_coord('x') + y * other.get_coord('y') + z * other.get_coord('z');
}
