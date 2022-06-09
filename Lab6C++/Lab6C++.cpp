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

vector <string> input_strings()
{
    cout << "Input text:" << endl;
    string line = "";
    string text;
    getline(cin, line);
    if (empty(line)) { cout << "Input at least one line:" << endl; }
    do
    {   text += line + " ";
        getline(cin, line);
    } while (!empty(line));
    vector <string> words;
    size_t pos;
    string word;
    while ((pos = text.find(" ")) != string::npos)
    {
        word = text.substr(0, pos);
        if (!empty(word))
        {
            if (word[word.length() - 1] == '.' or word[word.length() - 1] == ',')
                word.erase(word.length() - 1);
            words.push_back(word);
        }
        text.erase(0, pos + 1);
    }
    return words;

}

