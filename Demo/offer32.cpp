//
// Created by 廖洲洲 on 2020/10/4.
//

#include <bits/stdc++.h>

using namespace std;
//deque是双端队列
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
    vector<int> levelOrder(TreeNode *root) {
        vector<int> data;
        queue<TreeNode *> myQueue;
        if(root==NULL)
            return data;
        BFS(root,data,myQueue);
        return data;
    }
    void BFS(TreeNode *root,vector<int> &data,queue<TreeNode *> &myQueue){
        if(root==NULL)
            return;
        myQueue.push(root);
        TreeNode *node;
        while (!myQueue.empty()){
            node=myQueue.front();
            myQueue.pop();
            data.push_back(node->val);
            if(node->left)
                myQueue.push(node->left);
            if(node->right)
                myQueue.push(node->right);
        }
        return;
    }
};