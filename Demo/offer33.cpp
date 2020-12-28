//
// Created by 廖洲洲 on 2020/10/4.
//

#include <bits/stdc++.h>

using namespace std;
//二叉查找树（Binary SearchTree），（又：二叉搜索树，二叉排序树）
//它或者是一棵空树，或者是具有下列性质的二叉树
//若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值
//若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值
//它的左、右子树也分别为二叉排序树

class Solution {
public:
    bool verifyPostorder(vector<int> &postorder) {
        if (postorder.empty())
            return true;
        return verifyPostorderCore(postorder, 0, postorder.size() - 1);
    }

    bool verifyPostorderCore(vector<int> &postorder, int start, int end) {
        if (end <= start)
            return true;
        int greaterStart;
        int i = end - 1;
        while (i >= 0 && postorder[i] > postorder[end]) {
            i--;
        }
        greaterStart = i + 1;
        for (; i >= 0; i--) {
            if (postorder[i] > postorder[end])
                return false;
        }
        return verifyPostorderCore(postorder, start, greaterStart - 1) &&
               verifyPostorderCore(postorder, greaterStart, end - 1);
    }
};