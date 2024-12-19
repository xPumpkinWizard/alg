#include <iostream>
#include <fstream>
#include <string>
#include "trie.h"
using namespace std;

int main()
{
    trie T;
    //T.insert("doggie");

    ifstream infile("words2.txt");

    string word;
    while (infile >> word)
    {
        int freq;
        infile >> freq; //ignore for now

        T.insert(word);
    }

    //T.display();
    //world's worst autocomleter!
    while (true)
    {
        cout << "Please enter a prefix: " << endl;
        string pref;
        cin >> pref;
        cout << "You are probably trying to type: " << T.completion(pref) << endl;
    }

    return 0;
}