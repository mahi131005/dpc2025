#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cout<<"Enter the input string:";
    getline(cin, s);

    stringstream ss(s);
    string word;
    vector<string> wordList;

    while (ss >> word) {
        wordList.push_back(word);
    }

    reverse(wordList.begin(), wordList.end());

    string output;
    for (int i = 0; i < wordList.size(); i++) {
        if (i > 0) output += " ";
        output += wordList[i];
    }

    cout<<"Output:"<<output<<endl;
    return 0;
}
