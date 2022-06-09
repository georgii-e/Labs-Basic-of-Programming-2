#include "Tree.h"
#include <iostream>
#include <queue> 

Node* Tree::makeTree(vector<string> data)
{
    int i = 0;
    Node* root = new Node(data[i]);
    Node* curr_node = root;
    queue<Node*> st;
    st.push(curr_node);
    Node* left_node = NULL;
    Node* right_node = NULL;
    int n = data.size();
    bool isLeft = true;
    while (curr_node !=NULL && !st.empty())
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n)
        {
            Node* left_node = new Node(data[left]);
            curr_node->left = left_node;
        }
        st.push(curr_node->left);
        if (right < n)
        {
            Node* right_node = new Node(data[right]);
            curr_node->right = right_node;
        }
        st.push(curr_node->right);
        st.pop();
        curr_node = st.front();
        i++;
    }
	/*if (num == 0) return NULL;
	Node* node = new Node(data[word_index]);
	int num_left = num / 2;
	int num_right = num - num_left - 1;
	node->left = makeTree(data, word_index + 1, num_left);
	node->right = makeTree(data, word_index + num_left + 1, num_left);*/
	return root;
}

void Tree::printTree(const string& prefix, const Node* node, bool isLeft)
{
    if (node != nullptr)
    {
        cout << prefix;
        cout << (isLeft ? "|--" : "L--");
        cout << node->data << endl;
        printTree(prefix + (isLeft ? "|   " : "    "), node->left, true);
        printTree(prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}
