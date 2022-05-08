// Lab5C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TVector.h"
#include "TVector2.h"
using namespace std;
int main()
{
	TVector2 A(2, 3);
	TVector2 B(3, 4);
	cout << "Length of vector B: " << B.get_length() << endl;
	cout << "Scalar product of A and B: " << A.scalar(B) << endl;
}

