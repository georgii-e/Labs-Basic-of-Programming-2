class train_schedule:
    def __init__(self, route_number=0, direction_of_travel=None, departure_time="00:00", arrival_time="00:00"):
        self.route_number=route_number
        self.direction_of_travel=direction_of_travel
        self.departure_time=departure_time
        self.arrival_time=arrival_time

    def gett_info(self):
        print("Route number", self.route_number, "with destination",self.direction_of_travel, ", train leaves at",self.departure_time, "and arrives at", self.arrival_time)
    
    @classmethod
    def verify_time(cls, time_str):
        if time_str.find(":")==-1 or int(time_str.split(":")[0])<0 or int(time_str.split(":")[0])>24 or int(time_str.split(":")[-1])<0 or int(time_str.split(":")[-1])>60:
            print("Incorrect format of time")
            return False
        return True
