// Lab1C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	string path1 = "oldFile.txt";
	string path2 = "newFile.txt";
	string str, text;
	ofstream file_out(path1, ios::app);
	file_out << "fgfgdfg fguiu"; //���������� ���
	file_out.close();
	ifstream file_in(path1);
	if (!file_in.is_open())
	{
		cout << "Error" << endl;
		return 0;
	}
	while (!file_in.eof())
	{
		getline(file_in, str);
		text = text + str + "\n";
	}
	cout << text; 
	/*����� � 9 ���� ��� ��� ������� �� �����, ������� text_new � "�����������"
	�������, � ����� ������� ������������� ��, � �������� � ���� */
	file_in.close();

	file_out.open(path2, ios::app);
	file_out.close();
}


