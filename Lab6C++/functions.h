#pragma once
#include <string>
#include <vector>

using namespace std;

vector <string> input_strings();
vector<pair<string, int>> count_words(vector <string>);
void output_words(vector<pair<string, int>>);
