#include <iostream>
#include "Tree.h"
#include "functions.h"


int main()
{
    setlocale(LC_ALL, "ru");
    vector <string> words = input_strings();
    vector<pair<string, int>> words_count = count_words(words);
    output_words(words_count);
    words.clear();
    for (const auto& it : words_count)
        words.push_back(it.first);
    if (!words.empty()) 
    {
        Tree BinaryTree;
        Node* root = BinaryTree.makeTree(words);
        BinaryTree.printTree("", root, false);
    }

}

