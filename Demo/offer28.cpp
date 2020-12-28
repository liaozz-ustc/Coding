//
// Created by 廖洲洲 on 2020/10/3.
//
#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(root==NULL)
            return true;
        if(root->left==NULL&&root->right==NULL)
            return true;
        if(root->left&&root->right)
            return isSymmetricCore(root->left,root->right);
        return false;
    }
    bool isSymmetricCore(TreeNode * A,TreeNode *B){
        if(A==NULL&&B==NULL)
            return true;
        if(A&&B){
            if(A->val!=B->val){
                return false;
            }else{
                return isSymmetricCore(A->left,B->right)&&isSymmetricCore(A->right,B->left);
            }
        }
        return false;
    }

};
