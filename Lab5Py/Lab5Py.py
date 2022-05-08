from TVector2 import TVector2
from TVector3 import TVector3
import sys

print("Enter three coordinates for vector A:", end=" ")
x1, y1, z1 = map(int, sys.stdin.readline().split())
A = TVector3(x1, y1, z1)
print("Enter three coordinates for vector B:", end=" ")
x2, y2, z2 = map(int, sys.stdin.readline().split())
B = TVector3(x2, y2, z2)
print("Enter two coordinates for vector C:", end=" ")
x3, y3 = map(int, sys.stdin.readline().split())
C = TVector2(x3, y3)
print("Enter two coordinates for vector D:",end=" ")
x4, y4 = map(int, sys.stdin.readline().split())
D = TVector2(x4, y4)
S = A.scalar(B) + C.scalar(D) + A.get_length();
print("S = (A,B) + (C,D) + |A| = %.2f\n" % S)