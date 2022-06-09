#include "functions.h"
#include <map>
#include <algorithm>
#include <iostream>

vector<pair<string, int>> count_words(vector <string> words)
/*створення спочатку контейнера типу map для зберігання пар типу слово - кількість повторень,
що також дозволить автоматично запобігти потраплянню однаких слів у контейнер декількох разів,
а потім перетворення його у вектор пар для можливості сортування за кількістю повторень. */
{
    map <string, int> words_count;
    for (string word : words)
    {
        words_count[word] = count(words.begin(), words.end(), word);
    }
    vector<pair<string, int>> vector_of_words_count;
    for (const auto& it : words_count)
        vector_of_words_count.push_back(it);
    sort(vector_of_words_count.begin(), vector_of_words_count.end(),
        [](pair<string, int> a, pair<string, int> b) {return a.second > b.second; });
    return vector_of_words_count;
}
void output_words(vector<pair<string, int>> words_count)
{
    if (!empty(words_count))
    {
        cout << "Words with amount of repetition (total number of different words - "<< words_count.size()<<"):" << endl;
        for (const auto& it : words_count)
            cout << it.first << " - " << it.second << endl;
        cout << endl;
    }
    else cout << "You didn't enter any words";
}