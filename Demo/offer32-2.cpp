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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int> > data;
        if (!root)
            return data;
        deque<TreeNode *> myQueue1;
        deque<TreeNode *> myQueue2;
        TreeNode *node;
        vector<int> level;
        myQueue1.push_back(root);
        while (!myQueue1.empty()) {
            while (!myQueue1.empty()) {
                node = myQueue1.front();
                myQueue1.pop_front();
                level.push_back(node->val);
                if (node->left)
                    myQueue2.push_back(node->left);
                if (node->right)
                    myQueue2.push_back(node->right);
            }
           data.push_back(level);
            level.clear();
            while (!myQueue2.empty()) {
                node = myQueue2.front();
                myQueue2.pop_front();
                level.push_back(node->val);
                if (node->left)
                    myQueue1.push_back(node->left);
                if (node->right)
                    myQueue1.push_back(node->right);
            }
            if(!level.empty()){
                data.push_back(level);
                level.clear();
            }
        }
        return data;
    }
};