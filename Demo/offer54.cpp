//
// Created by 廖洲洲 on 2020/10/7.
//
#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


void inorder(struct TreeNode *root, int *k, int *knum) {
    if (root->right) {
        inorder(root->right, k, knum);
    }
    if (*k == 1) {
        *knum = root->val;
        *k=*k-1;
        return;
    }else{
        *k=*k-1;
    }
    if(*k<1)
        return;
    if (root->left)
        inorder(root->left, k, knum);
    return;
}



int kthLargest(struct TreeNode *root, int k) {
    if (!root)
        return -1;
    int knum;
    inorder(root, &k, &knum);
    return knum;
}
