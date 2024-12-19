#include "Autocompleter.h"

// Constructor: Initializes an empty Autocompleter with an empty trie.
Autocompleter::Autocompleter()
{
    root = new Node();
    count = 0;
}

// Inserts a string x with a frequency into the trie.
void Autocompleter::insert(string x, int freq)
{
    Node* current = root;

    // Traverse through the trie character by character
    for (int i = 0; i < x.size(); ++i)
    {
        if (current->children[x[i]] == nullptr)
        {
            current->children[x[i]] = new Node();
        }
        current = current->children[x[i]];


    }

    if (!current->marked) {
        current->marked = true;
        count++;
    }


}

// Returns the number of strings in the dictionary.
int Autocompleter::size()
{
    return count;
}

// Fills the vector T with the three most-frequent completions of the prefix x.
void Autocompleter::completions(string x, vector<string> &T)
{
    Node* current = root;


}
