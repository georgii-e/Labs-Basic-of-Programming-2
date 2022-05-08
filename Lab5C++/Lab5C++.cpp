#include <iostream>
#include "TVector.h"
#include "TVector2.h"
#include "TVector3.h"
using namespace std;
int main()
{ 
	float x1, y1, z1,
		  x2, y2, z2,
		  x3, y3,
		  x4, y4,
		  S;
	cout << "Enter three coordinates for vector A: ";
	cin >> x1 >> y1 >> z1;
	TVector3 A(x1, y1, z1);
	cout << "Enter three coordinates for vector B: ";
	cin >> x2 >> y2 >> z2;
	TVector3 B(x2, y2, z2);
	cout << "Enter two coordinates for vector C: ";
	cin >> x3 >> y3;
	TVector2 C(x3, y3);
	cout << "Enter two coordinates for vector D: ";
	cin >> x4 >> y4;
	TVector2 D(x4, y4);
	S = A.scalar(B) + C.scalar(D) + A.get_length();
	printf("S = (A,B) + (C,D) + |A| = %.2f\n", S);
}

