//
// Created by 廖洲洲 on 2020/10/4.
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
    //将引用变量提为全局变量能提高时间
    vector<vector<int>> allPath;
    vector<int> valPath;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        if(!root)
            return allPath;

        pathSumCore(root,sum);
        return allPath;
    }
    void pathSumCore(TreeNode *root,int sum){
        if(!root->left&&!root->right){
            //当是叶子节点
            if(sum==root->val){
                valPath.push_back(root->val);
                allPath.push_back(valPath);
                valPath.pop_back();
            }
            return;
        }
        if(root->left){
            valPath.push_back(root->val);
            pathSumCore(root->left,sum-root->val);
            valPath.pop_back();
        }
        if(root->right){
            valPath.push_back(root->val);
            pathSumCore(root->right,sum-root->val);
            valPath.pop_back();
        }
        return;
    }
};