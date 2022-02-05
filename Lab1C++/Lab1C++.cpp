// Lab1C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void text_to_file(string);
string text_from_file(string);
string N_times(string, int);
int main()
{
	string path1 = "oldFile.txt";
	string path2 = "newFile.txt";
	int n;
	text_to_file(path1);
	string text=text_from_file(path1);
	cout << "Write number of repetitions: ";
	cin >> n;
	string words=N_times(text, n);
	cout << words;
}
void text_to_file(string path)
{
	ofstream file_out(path, ios::trunc);
	string temp_str ="";
	if (!file_out.is_open())
	{
		cout << "Failed to open the file";
	}
	else
	{
		cout << "Write your text in the console below \nTo stop adding new text enter \"leave\"" << endl;
		while (temp_str!="leave\n")
		{
			file_out << temp_str;
			cout << "enter a new line: ";
			getline(cin,temp_str);
			temp_str += '\n';
		}
	}

	file_out.close();
}
string text_from_file(string path)
{
	string str, text;
	ifstream file_in(path);
	if (!file_in.is_open())
	{
		cout << "Error" << endl;
		return 0;
	}
	while (!file_in.eof())
	{
		getline(file_in, str);
		text = text + str + " " + "\n" + " ";
	}
	cout << text;
	/*проверять нет ли слова в полученом списке, если есть, то осталвяем, если нет, удаляем, потом в новой функции отсортировать их, и записать в файл */
	file_in.close();
	return text;
}
string N_times(string text, int n)
{
	size_t pos = 0;
	string word, words_that_repeats;
	string text_copy;
	string delimiter = " ";
	string new_phrase = "";
	while ((pos = text.find(delimiter)) != string::npos)
	{
		text_copy = text;
		word = text.substr(0, pos);
		int count=0;
		while (text_copy.find(word) != -1 && word!="\n" && words_that_repeats.find(word) == -1)
		{
			text_copy.erase(text_copy.find(word), word.length()+1);
			count++;
			if (count > n && words_that_repeats.find(word)==-1)
			{
				words_that_repeats += word + " ";
			}
		}
		text.erase(0, pos + delimiter.length()); //+1
	}
	return words_that_repeats;
}
