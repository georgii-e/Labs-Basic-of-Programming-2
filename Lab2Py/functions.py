from class_train_schedule import train_schedule
import pickle
def create_schedule(path):
    number_of_trains=int(input("Input amount of trains: "))
    print("Format of time: xx:xx or x:xx")
    for i in range(number_of_trains):
        route_number=input("\nInput route number: ")
        direction_of_travel=input("Input direction: ")
        departure_time=input("Input departure time: ")
        while not train_schedule.verify_time(departure_time):
            departure_time=input("Input departure time: ")
        arrival_time=input("Input arrival time: ")
        while not train_schedule.verify_time(arrival_time):
            arrival_time=input("Input arrival time: ")
        print()
        A=train_schedule(route_number,direction_of_travel,departure_time,arrival_time)
        write_to_file(path, A)
def read_from_file(path, message):
    print(message)
    array_of_objects=[]
    try:
        with open(path,'rb') as text_from_file:
            while True:
                try:
                    A=pickle.load(text_from_file)
                except:
                    break
                else:
                    flag=True
                    array_of_objects.append(A)
                    A.gett_info()
    except:
        print("Empty schedule")
    return array_of_objects
def write_to_file(path, train):
    with open(path,'ab') as text_in_file:
        pickle.dump(train, text_in_file)
def winter_schedule(array_of_objects, path):
    max_time=18
    min_time=10
    for i in range (len(array_of_objects)):
        time_int=int(array_of_objects[i].departure_time.split(":")[0])
        if time_int<min_time or time_int>max_time:
            write_to_file(path, array_of_objects[i])
