#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string input(); //читання тексту з консолі
void text_to_file(string, string); //записування тексту в файл
string text_from_file(string); //читання тексту з файла
int split_string(string, string*); //перетворення рядка масив слів, повертає їх кількість
string processing(string, int); //виділення слів що повторюються, функія також викликає функцію сортування
string sort(string*, int); //сортує слова
int main()
{
	string path1 = "oldFile.txt";
	string path2 = "newFile.txt";
	int n;
	string text_to_write = input();
	text_to_file(text_to_write, path1);
	string text_to_read=text_from_file(path1);
	cout << "Write number of repetitions: ";
	cin >> n;
	string sorted_words= processing(text_to_read, n);
	cout << sorted_words;
	text_to_file(sorted_words, path2);
}
string input()
{
	string temp_str;
	string text;
	cout << "Write your text in the console below \nPress Ctrl+x and then \"Enter\" to finish" << endl;
	cout << "enter a new line: ";
	getline(cin, temp_str);
	while (temp_str != "\x18")
	{
		cout << "enter a new line: ";
		text += temp_str + '\n';
		getline(cin, temp_str);
	}
	return text;
}
void text_to_file(string text, string path)
{
	ofstream file_out(path, ios::trunc);
	if (!file_out.is_open())
	{
		cout << "Failed to open the file";
	}
	else
		file_out << text;
	file_out.close();
}
string text_from_file(string path)
{
	string str, text;
	ifstream file_in(path);
	cout << endl;
	cout << "You input:" << endl;
	if (!file_in.is_open())
	{
		cout << "Error" << endl;
	}
	while (!file_in.eof())
	{
		getline(file_in, str);
		cout << str << endl;
		text += str + " ";
	}
file_in.close();
return text;
}
int split_string(string text, string* str_arr) {
	size_t pos;
	string word;
	int i = 0;
	while ((pos = text.find(" ")) != string::npos) {
		word = text.substr(0, pos);
		if (!empty(word)) {
			str_arr[i] = word;
			i++;
		}
		text.erase(0, pos + 1);

	}
	return i;
}
string processing(string text, int n)
{
	size_t len = text.length();
	string* word_arr = new string[len];
	int amount_of_words = split_string(text, word_arr);
	string* new_word_arr = new string[amount_of_words];
	int k = 0;
	for (int i = 0; i < amount_of_words - 1; i++) 
	{
		int counter = 1;
		for (int j = i + 1; j < amount_of_words; j++) 
		{
			if (word_arr[i] == word_arr[j] && word_arr[i]!="")
			{
				word_arr[j] = "";
				counter++;
			}
		}
		if (counter > n) {
			new_word_arr[k] = word_arr[i];
			k++;
		}

	}
	string new_text = sort(new_word_arr, k);
	delete[]word_arr;
	delete[]new_word_arr;
	return new_text;
}
string sort(string* word_arr, int size)
{
	string tmp, text;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (word_arr[j].length() > word_arr[j + 1].length())
			{
				tmp = word_arr[j];
				word_arr[j] = word_arr[j + 1];
				word_arr[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < size; i++) //об'єднання масиву у рядок
	{
		if (word_arr[i]!="")
			text += word_arr[i] + " ";
	}
	return text;
}