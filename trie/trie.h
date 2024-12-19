#pragma once
#include <iostream>
#include <string>
using namespace std;

class trie
{
private:
    class node
    {
    public:
        bool marked;
        node* children[256];

        //augmentation: keep track
        //of coolest word in this node's sub-trie
        string coolest; //actually longest in this case

        node()
        {
            marked = false;
            for (int i = 0; i < 256; i++)
                children[i] = nullptr;
        }
    };

    node* root;

    //display all the words in the
    //trie rooted at node p, with
    //the word pref stuck on the front.
    void recDisplay(node* p, string pref)
    {
        if (p == nullptr)
        {
            //uh, no tree, do nothing
        }
        else
        {
            //deal with p node
            if (p->marked)
                cout << pref << endl;

            for (int i = 0; i < 256; i++)
            {
                recDisplay(p->children[i], pref + (char)i);
            }
        }
    }

    //return the number of strings in trie rooted
    //at node p.
    int numStrings(node* p)
    {

    }

public:
    trie()
    {
        root = new node;
    }

    void insert(string s)
    {
        //cout << s << endl;
        node * yellowArrow = root;

        for (int i = 0; i < s.size(); i++)
        {
            if (yellowArrow->children[s[i]] == nullptr)
                yellowArrow->children[s[i]]=new node;

            yellowArrow = yellowArrow->children[s[i]];

            //Augmentation:
            //check is s is cooler than yellow's coolest
            if (s.size() > yellowArrow->coolest.size())
                yellowArrow->coolest = s;
        }

        yellowArrow->marked = true;
    }

    //return coolest (longest) completion of pref
    string completion(string pref)
    {
        node* ya = root;
        for (int i = 0; i < pref.size(); i++)
        {
            ya = ya->children[pref[i]];

            if (ya == nullptr)
                return pref;
        }

        return ya->coolest;
    }

    void display()
    {
        recDisplay(root, "");
    }

    int numStrings()
    {
        return numStrings(root);
    }
};