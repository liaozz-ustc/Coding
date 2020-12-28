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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> data;
        if(!root)
            return data;
        stack<TreeNode *> level1;
        stack<TreeNode *> level2;
        vector<int> tmp;
        TreeNode *node;
        level1.push(root);
        while(!level1.empty()){
            while (!level1.empty()){
                node=level1.top();
                level1.pop();
                tmp.push_back(node->val);
                if(node->left)
                    level2.push(node->left);
                if(node->right)
                    level2.push(node->right);
            }
            data.push_back(tmp);
            tmp.clear();
            while (!level2.empty()){
                node=level2.top();
                level2.pop();
                tmp.push_back(node->val);
                if(node->right)
                    level1.push(node->right);
                if(node->left)
                    level1.push(node->left);
            }
            if(!tmp.empty()){
                data.push_back(tmp);
                tmp.clear();
            }
        }
        return data;
    }
};