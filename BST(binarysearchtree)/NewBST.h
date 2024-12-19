//
// Created by miguel hernandez on 4/26/23.
//
#include <iostream>
#include "TreeNode.h"
using namespace std;

#ifndef BST_BINARYSEARCHTREE__NEWBST_H


// is binary search tree unique
// [9,-1,14,1,6,-3,2,0]

/*
 *             root & temp
 *                  9
 *                /   \
 *              -1      14
 *             /  \
 *           -3    1
 *                /  \
 *                0   6
 *                   /
 *                  2
 *
 *    Intuitive solution
 *  bool findVal(Node* root, int target){
 *      iteration
 *          ->initialize
 *              make a pointer to bookmark our,
 *              location Node* temp = root;
 *          ->continue condition
 *              until Target is found,
 *              or we hit a nulllptr:
 *
 *           ** while the temp pointer is not,
 *              null : check if the temp data is
 *              target
 *              // if Yes
 *                  return true;
 *
 *              // if No
 *                  is temp->data < target
 *                      // Yes
 *                          "temp" should go right
 *                          go to **
*                       // No
 *                          "temp" moves left
 *                          go to **
 *
 *
 *          ->update
 *  }
 */

    bool findVal(TreeNode* root, int target){
        //step one
        TreeNode* temp = root;

        while (temp != nullptr) {
            // search
            if(temp->data == target){
                // we found it
                cout << "Found!" << endl;
                return true;
            } else { // temp will be updated
                // check where we should go next
                if (target < temp->data ) {
                    cout << "Found value: " << temp->data << ", looking for: " << target << endl;
                    cout << "Move left..." << endl;
                    // move temp left
                    temp = temp->left;
                } else {
                    cout << "Found value: " << temp->data << ", looking for: " << target << endl;
                    cout << "Move right..." << endl;
                    // move temp right
                    temp = temp->right;
                }
            }


            // if not found
            cout << "Value Not Found!" << endl;
            return false;
        }

    }
/*
 *              Recursive Solution
 *  bool findValR(Node* root, int target){
 *      Base Cases
 *          ->root is null  (there are no values)
 *              -> return false;
 *                  >root is target
 *              -> return true;
 *
 *      General Case
 *          if (target < root->data){
 *              root = root->left;
 *                  ->findValR(root->left, target)
 *              }else{
 *                  ->findValR(root->right, target)
 *              }
 *  }
 *
 */

 bool findValR(TreeNode* root, int target){
     // Base Cases
    if (root == nullptr){
        return false;
    }else if (root->data == target){
        return true;
    }
        //General Case
    else{
        if (target < root->data){
           root = root->left;
           findValR(root->left, target);
            }
        else{
            findValR(root->right, target);

        }
    }

    root is target
    *              -> return true;
    *
            *      General Case
    *          if (target < root->data){
        *              root = root->left;
        *                  ->findValR(root->left, target)
                             *              }else{
        *                  ->findValR(root->right, target)
                             *              }
    *  }






#define BST_BINARYSEARCHTREE__NEWBST_H

#endif //BST_BINARYSEARCHTREE__NEWBST_H
