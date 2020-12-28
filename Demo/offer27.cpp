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
    TreeNode *mirrorTree(TreeNode *root) {
        if(root==NULL)
            return NULL;
        TreeNode *tmp;
        tmp=root->left;
        root->left=root->right;
        root->right=tmp;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};