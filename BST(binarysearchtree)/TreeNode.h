//
// Created by miguel hernandez on 4/24/23.
//
#include <iostream>
using namespace std;


#ifndef BST_BINARYSEARCHTREE__TREENODE_H

class TreeNode{
public:

    int data;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int indata = 0){
        data = indata;
        right = nullptr;
        left = nullptr;
    }

};

#define BST_BINARYSEARCHTREE__TREENODE_H

#endif //BST_BINARYSEARCHTREE__TREENODE_H
