//
// Created by 廖洲洲 on 2020/10/4.
//

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node *treeToDoublyList(Node *root) {
        if (!root)
            return NULL;
        if (!root->left && !root->right) {
            root->left = root;
            root->right = root;
            return root;
        }
        Node *leftHead = treeToDoublyList(root->left);
        Node *rightHead = treeToDoublyList(root->right);
        if (leftHead && rightHead) {
            root->left = leftHead->left;
            root->right = rightHead;
            leftHead->left = rightHead->left;
            rightHead->left->right = leftHead;
            root->left->right = root;
            root->right->left = root;
            return leftHead;
        } else if(leftHead)
        {
            root->left = leftHead->left;
            root->right = leftHead;
            leftHead->left = root;
            root->left->right = root;
            return leftHead;
        }else{
            root->right = rightHead;
            root->left = rightHead->left;
            rightHead->left = root;
            root->left->right = root;
            return root;
        }
    }
};