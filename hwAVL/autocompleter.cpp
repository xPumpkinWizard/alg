#include "autocompleter.h"
#include <algorithm>

// Insert a string with a frequency into the dictionary
// If the string already exists, update its frequency.
void Autocompleter::insert(string x, int freq) {
    Entry e;
    e.s = x;
    e.freq = freq;
    insert_recurse(e, root);
}

// Recursive helper function for inserting an Entry into an AVL tree.
void Autocompleter::insert_recurse(Entry e, Node* &p) {
    if (p == nullptr) {
        p = new Node(e);
    } else if (e.s < p->e.s) {
        insert_recurse(e, p->left);
    } else if (e.s > p->e.s) {
        insert_recurse(e, p->right);
    }

    // Update the height of the current node.
    update_height(p);

    // Rebalance the tree.
    rebalance(p);
}

// Rebalance the AVL tree rooted at p.
void Autocompleter::rebalance(Node* &p) {
    if (p == nullptr) return;

    int balance = height(p->left) - height(p->right);

    if (balance > 1) {
        if (height(p->left->left) >= height(p->left->right)) {
            right_rotate(p);
        } else {
            left_rotate(p->left);
            right_rotate(p);
        }
    } else if (balance < -1) {
        if (height(p->right->right) >= height(p->right->left)) {
            left_rotate(p);
        } else {
            right_rotate(p->right);
            left_rotate(p);
        }
    }
}

// Right rotation of an AVL tree rooted at p.
void Autocompleter::right_rotate(Node* &p) {
    Node* newRoot = p->left;
    p->left = newRoot->right;
    newRoot->right = p;
    p = newRoot;

    update_height(p->right);
    update_height(p);
}

// Left rotation of an AVL tree rooted at p.
void Autocompleter::left_rotate(Node* &p) {
    Node* newRoot = p->right;
    p->right = newRoot->left;
    newRoot->left = p;
    p = newRoot;

    update_height(p->left);
    update_height(p);
}

// Returns the size of the dictionary
int Autocompleter::size() {
    return size_recurse(root);
}

// Recursive helper function for computing the size of the tree rooted at p.
int Autocompleter::size_recurse(Node* p) {
    if (p == nullptr) {
        return 0;
    } else {
        return 1 + size_recurse(p->left) + size_recurse(p->right);
    }
}

// Returns the three most frequent completions of a string x.
void Autocompleter::completions(string x, vector<string> &T) {
    vector<Entry> completions;
    completions_recurse(x, root, completions);

    sort(completions.begin(), completions.end(), [](const Entry &a, const Entry &b) {
        if (a.freq == b.freq) {
            return a.s < b.s;
        }
        return a.freq > b.freq;
    });

    for (int i = 0; i < min(3, static_cast<int>(completions.size())); i++) {
        T.push_back(completions[i].s);
    }
}

// Recursive helper function for finding completions in the tree rooted at p.
void Autocompleter::completions_recurse(string x, Node* p, vector<Entry> &C) {
    if (p == nullptr) return;
    if (p->e.s.find(x) == 0) {
        C.push_back(p->e);
    }

    if (x < p->e.s || x == p->e.s) {
        completions_recurse(x, p->left, C);
    }
    if (x > p->e.s || x == p->e.s) {
        completions_recurse(x, p->right, C);
    }
}


