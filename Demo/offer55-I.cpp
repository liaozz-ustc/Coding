//
// Created by 廖洲洲 on 2020/10/7.
//

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode *root, int k, int *max) {
    if (!root) {
        if (k > *max)
            *max = k;
        return;
    }
    dfs(root->left, k + 1, max);
    dfs(root->right, k + 1, max);
    return;
}

int maxDepth(struct TreeNode *root) {
    if (!root)
        return 0;
    int max = 0;
    dfs(root, 0, &max);
    return max;
}

//bool isBalanced(struct TreeNode *root) {
//    if (!root)
//        return true;
//    return abs(maxDepth(root->left) - maxDepth(root->right)) <= 1
//           && isBalanced(root->left)
//           && isBalanced(root->right);
//}
bool isBalancedCore(struct TreeNode *root,int *depth){
    if(!root){
        *depth=0;
        return true;
    }
    int left,right;
    if(isBalancedCore(root->left,&left)
    &&isBalancedCore(root->right,&right)){
        int diff=left-right;
        if(diff<=1&&diff>=-1){
            *depth=1+(left>right?left:right);
            return true;
        }
    }
    return false;
}
bool isBalanced(struct TreeNode* root){
    int depth=0;
    return isBalancedCore(root,&depth);
}
