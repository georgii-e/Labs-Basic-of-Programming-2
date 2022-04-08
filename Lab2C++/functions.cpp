#include "functions.h"
#include "struct_train_schedule.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
void write_in_file(string path, train_schedule train)
{
	ofstream f_out(path, ios::binary | ios::app);
	f_out.write((char*)&train, sizeof(train_schedule));
	f_out.close();
}
void create_schedule(string path)
{
	int num_trains;
	train_schedule train;

	cout << "Input number of trains: ";
	cin >> num_trains;
	cin.ignore();
	cout << "Use format of time: xx:xx or x:xx" << endl;
	for (int i = 0; i < num_trains; i++)
	{
		cout << endl;
		cout << "Input route number: ";
		cin.getline(train.route_number, 7);
		cout << "Input direction: ";
		cin.getline(train.direction_of_travel, 16);
		cout << "Input departure time: ";
		cin.getline(train.departure_time, 6);
		while (!verify_time(train.departure_time))
		{
			cout << "Input departure time: ";
			cin.getline(train.departure_time, 6);
		}
		cout << "Input arrival time: ";
		cin.getline(train.arrival_time, 6);
		while (!verify_time(train.arrival_time))
		{
			cout << "Input arrival time: ";
			cin.getline(train.arrival_time, 6);
		}
		write_in_file(path, train);
	}

}
void output_schedule(string path, string message)
{
	train_schedule train;
	ifstream f_in(path, ios::binary);
	cout << endl;
	cout << message << endl;
	if (!f_in.is_open())
	{
		cout << "Empty schedule" << endl;
	}

	while (f_in.read((char*)&train, sizeof(train_schedule)))
	{
		cout << endl;
		cout << "Route number: " << train.route_number << endl;
		cout << "With destination: " << train.direction_of_travel << endl;
		cout << "Leave at: " << train.departure_time << " o'clock" << endl;
		cout << "Arrive at: " << train.arrival_time << " o'clock" << endl;
	}
	f_in.close();
}
void winter_chedule(string path1, string path2)
{
	const int max_time = 18;
	const int min_time = 10;
	train_schedule train;
	vector <train_schedule> trains;
	string departure_time;
	int time;
	int pos;
	ifstream f_in(path1, ios::binary);
	if (!f_in.is_open())
	{
		cout << "Error" << endl;
	}
	cout << endl;
	while (f_in.read((char*)&train, sizeof(train_schedule)))
	{
		trains.push_back(train);
	}
	f_in.close();
	for (auto train_ : trains)
	{
		departure_time = train_.departure_time;
		pos = departure_time.find(':');
		time = stoi(departure_time.erase(pos, 3));
		if (time < min_time or time>max_time)
		{
			write_in_file(path2, train_);
		}
	}

}
bool verify_time(char* char_time)
{
	string time = char_time;
	int pos = time.find(':');
	int minutes = stoi(time.substr(pos + 1, time.length() - pos));
	int hours = stoi(time.substr(0, pos));
	if (pos == -1 or hours > 24 or hours < 0 or minutes > 60 or minutes < 0)
	{
		cout << "Incorrect format of time" << endl;
		return false;
	}
	return true;
}