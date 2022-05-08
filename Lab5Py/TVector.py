from abc import ABC, abstractmethod
from abc import abstractclassmethod

class TVector(ABC):
    def __init__(self):
        super().__init__()
    @abstractmethod
    def get_length():
        pass
    @abstractmethod
    def get_coord(coord):
        pass
    @abstractmethod
    def scalar(other):
        pass




