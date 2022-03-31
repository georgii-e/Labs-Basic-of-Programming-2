import functions as f
import os

path1="Summer.bin"
path2="Winter.bin"
try:
    os.remove(path1)
except:
    pass
try:
    os.remove(path2)
except:
    pass
array_of_objects=[]
f.create_schedule(path1)
array_of_objects=f.read_from_file(path1, "\nSummer schedule:")
f.winter_schedule(array_of_objects, path2)
f.read_from_file(path2, "\nWinter schedule:")