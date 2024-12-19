#include "autocompleter.h"

Autocompleter::Autocompleter() {
    root = nullptr;
}

void Autocompleter::insert(string x, int freq) {
    Entry e;
    e.s = x;
    e.freq = freq;
    insert_recurse(e, root);
}

int Autocompleter::size() {
    return size_recurse(root);
}

void Autocompleter::completions(string x, vector<string>& T) {
    T.clear();
    vector<Entry> completions;
    completions_recurse(x, root, completions);

    sort(completions.begin(), completions.end(), [](const Entry &a, const Entry &b) {
        return a.freq > b.freq;
    });

    int limit = (completions.size() < 3) ? completions.size() : 3;

    for (int i = 0; i < limit; ++i) {
        T.push_back(completions[i].s);
    }
}

int Autocompleter::size_recurse(Node* p) {
    if (p == nullptr) {
        return 0;
    }
    return 1 + size_recurse(p->left) + size_recurse(p->right);
}

void Autocompleter::completions_recurse(string x, Node* p, vector<Entry>& C) {
    if (p == nullptr) {
        return;
    }
    int cmp = x.compare(0, x.length(), p->e.s, 0, x.length());

    if (cmp <= 0) {
        completions_recurse( x,p->left, C);
    }
    if (cmp == 0) {
        C.push_back({p->e.s, p->e.freq});
    }
    if (cmp >= 0) {
        completions_recurse(x, p->right, C);
    }
}

void Autocompleter::insert_recurse(Entry e, Node* &p) {
    if (p == nullptr) {
        p = new Node(e);
    } else {
        if (e.s < p->e.s) {
            insert_recurse(e, p->left);
        } else {
            insert_recurse(e, p->right);
        }
        update_height(p);
        rebalance(p);
    }
}

void Autocompleter::rebalance(Node* &p) {
    if (p == nullptr) {
        return;
    }
    int avlRule = height(p->left) - height(p->right);

    if (avlRule > 1) {
        if (height(p->left->left) < height(p->left->right)) {
            left_rotate(p->left);
        }
        right_rotate(p);
    } else if (avlRule < -1) {
        if (height(p->right->right) < height(p->right->left)) {
            right_rotate(p->right);
        }
        left_rotate(p);
    }
}

void Autocompleter::right_rotate(Node* &p) {
    Node* A = p;
    Node* B = p->left;
    Node* bRight = B->right;

    p = B;
    B->right = A;
    A->left = bRight;

    update_height(A);
    update_height(B);
}

void Autocompleter::left_rotate(Node* &p) {
    Node* A = p;
    Node* B = p->right;
    Node* bLeft = B->left;

    p = B;
    B->left = A;
    A->right = bLeft;

    update_height(A);
    update_height(B);
}