// Lab2C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "struct_train_schedule.h"
#include "functions.h"



using namespace std;


int main()
{
	string path1 = "summer.bin";
	string path2 = "winter.bin";
	remove(path1.c_str());
	remove(path2.c_str());
	create_schedule(path1);
	output_schedule(path1, "Summer schedule:");
	winter_chedule(path1, path2);
	output_schedule(path2,"Winter schedule:");
	return 0;
}
