from TVector import TVector
from math import sqrt
from math import pow

class TVector3(TVector):
    def __init__(self, x=0, y=0, z=0):
        self.__x=x 
        self.__y=y
        self.__z=z
    def get_length(self):
        return sqrt(pow(self.__x,2)+pow(self.__y,2)+pow(self.__z,2))
    def get_coord(self, coord):
        if coord=='x':
            return self.__x
        elif coord=='y':
            return self.__y
        else:
            return self.__z
    def scalar(self, other):
        return self.__x*other.get_coord('x')+self.__y*other.get_coord('y')+self.__z*other.get_coord('z')




