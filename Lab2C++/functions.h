#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
struct train_schedule;
void write_in_file(string path, train_schedule train);
void create_schedule(string path);
void output_schedule(string path, string message);
void winter_chedule(string path1, string path2);
bool verify_time(char* char_time);
