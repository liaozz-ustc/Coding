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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==NULL||B==NULL)
            return false;
        return isSubStructureCore(A,B)||isSubStructure(A->left,B)||isSubStructure(A->right,B);
    }
    bool isSubStructureCore(TreeNode * A,TreeNode *B){
        if(B==NULL)
            return true;
        if(A==NULL)
            return false;
        if(A->val==B->val){
            return isSubStructureCore(A->left,B->left)&&isSubStructureCore(A->right,B->right);
        }
        return false;

    }
};