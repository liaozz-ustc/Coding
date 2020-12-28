//
// Created by 廖洲洲 on 2020/10/4.
//
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (!root)
            return "[]";
        string treeToString;
        treeToString = "[";
        queue<TreeNode *> myQueue;
        myQueue.push(root);
        int num = 1;
        TreeNode *node;
        while (num) {
            node = myQueue.front();
            myQueue.pop();
            if (node) {
                num--;
                treeToString = treeToString + to_string(node->val) + ",";
                myQueue.push(node->left);
                myQueue.push(node->right);
                if (node->left)
                    num++;
                if (node->right)
                    num++;
            } else {
                treeToString = treeToString + "null,";
//                myQueue.push(NULL);
//                myQueue.push(NULL);
            }
        }
        treeToString = treeToString.substr(0, treeToString.length() - 1) + "]";
        return treeToString;

    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data == "[]")
            return NULL;
        data = data.substr(1, data.size() - 2);
        data = data + ',';
        cout<<data<<endl;
        TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));
        int pos;
        string str;
        pos=data.find(',');
        str = data.substr(0, pos);
        data = data.substr(pos + 1);
        root->val=stoi(str);
        queue<TreeNode *> myQueue;
        myQueue.push(root);
        TreeNode *Node;
        while (!myQueue.empty()) {
            Node = myQueue.front();
            myQueue.pop();
            pos = data.find(",");
            if (pos != data.npos) {
                str = data.substr(0, pos);
                data = data.substr(pos + 1);
                if (str == "null") {
                    Node->left = NULL;
                } else {
                    Node->left = (TreeNode *) malloc(sizeof(TreeNode));
                    Node->left->val = stoi(str);
                    myQueue.push(Node->left);
                }
            }else{
                Node->left=NULL;
            }
            pos = data.find(",");
            if (pos != data.npos) {
                str = data.substr(0, pos);
                data = data.substr(pos + 1);
                if (str == "null") {
                    Node->right = NULL;
                } else {
                    Node->right = (TreeNode *) malloc(sizeof(TreeNode));
                    Node->right->val = stoi(str);
                    myQueue.push(Node->right);
                }
            }else{
                Node->right=NULL;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
int main() {
    TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));
    root->val = 1;
    root->left = (TreeNode *) malloc(sizeof(TreeNode));
    root->left->val = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (TreeNode *) malloc(sizeof(TreeNode));
    root->right->val = 3;
    root->right->left = (TreeNode *) malloc(sizeof(TreeNode));
    root->right->right = NULL;
    root->right->left->val = 4;
    root->right->left->left = NULL;
    root->right->left->right = NULL;

    Codec codec;
    cout << codec.serialize(root)<<endl;
    cout<<codec.serialize(codec.deserialize(codec.serialize(root)))<<endl;
    return 0;
}