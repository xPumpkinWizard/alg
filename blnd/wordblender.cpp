#include "wordblender.h"
#include <unordered_map>
#include <vector>
#include <stdexcept>
#include <fstream>

using namespace std;

// Constructor
WordBlender::WordBlender(string filename, int max_word_count)
        : max_word_count(max_word_count)
{
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Could not open file.");
    }

    vector<string> words;
    unordered_map<string, vector<string>> suffix_map;

    string word;
    while (file >> word) {
        words.push_back(word);
        string suffix = word.substr(word.size() - 2);
        suffix_map[suffix].push_back(word);
    }
    file.close();

    // Create the table for precomputed blends
    int num_words = words.size();
    table = new string*[num_words];
    for (int i = 0; i < num_words; ++i) {
        table[i] = new string[max_word_count + 1]();
        table[i][1] = words[i]; // Base case: single word blends

        for (int count = 2; count <= max_word_count; ++count) {
            string suffix = table[i][count - 1].substr(table[i][count - 1].size() - 2);
            if (suffix_map.count(suffix)) {
                table[i][count] = table[i][count - 1] + suffix_map[suffix][0].substr(2);
            } else {
                table[i][count] = ""; // No further blends possible
                break;
            }
        }
    }
}

// Blend function
string WordBlender::blend(string first_word, string last_word, int word_count)
{
    for (int i = 0; table[i][1] != ""; ++i) {
        if (table[i][1] == first_word && !table[i][word_count].empty() &&
            table[i][word_count].substr(table[i][word_count].size() - last_word.size()) == last_word) {
            return table[i][word_count];
        }
    }
    return ""; // No valid blend found
}
