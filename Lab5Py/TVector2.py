from TVector import TVector
from math import sqrt

class TVector2(TVector):
    def __init__(self, x=0, y=0):
        self.__x=x 
        self.__y=y
    def get_length(self):
        return sqrt(self.__x*self.__x+self.__y*self.__y)
    def get_coord(self, coord):
            return self.__x if coord=='x' else self.__y
    def scalar(self, other):
        return self.__x*other.get_coord('x')+self.y*other.get_coord('y')

    
   




