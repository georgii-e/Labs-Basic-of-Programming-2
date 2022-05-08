#include "TVector2.h"
#include<math.h>
TVector2::TVector2(float x, float y)
{
	this->x = x;
	this->y = y;
}
float TVector2::get_coord(char coord)
{
	switch (coord)
	{
	case 'x':
		return x;
		break;
	case 'y':
		return y;
		break;
	}
}
float TVector2::get_length()
{
	return sqrt(x * x + y * y);
}
float TVector2::scalar(TVector& other)
{
	return x*other.get_coord('x')+y*other.get_coord('y');
}

