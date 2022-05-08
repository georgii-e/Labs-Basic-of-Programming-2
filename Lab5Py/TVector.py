from abc import ABC, abstractmethod
from abc import abstractclassmethod

class TVector(ABC):
    @abstractmethod
    def get_length():
        pass
    @abstractmethod
    def get_coord(coord):
        pass
    @abstractmethod
    def scalar(other):
        pass




