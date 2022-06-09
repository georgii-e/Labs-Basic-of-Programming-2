#pragma once
#include <string>
#include <vector>

using namespace std;

struct Node
{
	string data;
	Node* left, * right;
	Node(string word) : data(word), left(NULL), right(NULL) {};
};
class Tree
{
	Node* root;
public:
	Tree() :root(NULL) {};
	Node* makeTree(vector<string>);
	void printTree(const string&, const Node*, bool);

};

