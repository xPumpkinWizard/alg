//
// Created by miguel hernandez on 4/24/23.
//

#include <iostream>
#include "TreeNode.h"
using namespace std;



#ifndef BST_BINARYSEARCHTREE__BST_H

    //      8
    //  /       \
    //  null



    // class DemoTree
    // fill values correctly for the following
    // {0, -6,1,8,7,14}

    class DemoTree{
    public:

        TreeNode* root;
        DemoTree(){
            root = new TreeNode(0);
            // fill more values
            // set left and right
            root->left = new TreeNode(-6);
            root-> right = new TreeNode(3);

            // fill in the rest
            // fill the children of the "3"
            root->right->left = new TreeNode(1);
            root->right->right = new TreeNode(8);

            // children of "1" node?

            // children of "8" node
            root->right->right->right = new TreeNode(14);
            root->right->left->left = new TreeNode(7);



    }

};

    int countLeafs(TreeNode* root){
        if(root == nullptr){
            return 0;
        }else if(root->right == nullptr && root->left == nullptr){
            return 1;
        }else if(root->right != nullptr){
            if(root->left != nullptr){
                return 2;
            }
            return 1;
        }else{return 1;}
    }

// recursive solution
    int count(TreeNode* root){
        //base
        // check if the tree is empty
        if(root == nullptr){
            return 0;
        }
            // reads the right and left of the branch
        else{
            return 1 + count(root->right) + count(root->left);
        }
    }




#define BST_BINARYSEARCHTREE__BST_H

#endif //BST_BINARYSEARCHTREE__BST_H
