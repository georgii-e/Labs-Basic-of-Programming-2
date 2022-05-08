from TVector import TVector
from math import sqrt
from math import pow

class TVector2(TVector):
    def __init__(self, x=0, y=0):
        self.__x=x 
        self.__y=y
    def get_length(self):
        return sqrt(pow(self.__x,2)+pow(self.__y,2))
    def get_coord(self, coord):
            return self.__x if coord=='x' else self.__y
    def scalar(self, other):
        return self.__x*other.get_coord('x')+self.__y*other.get_coord('y')

    
   




