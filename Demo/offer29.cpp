//
// Created by 廖洲洲 on 2020/10/3.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> result;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return result;
        spiralOrderCore(matrix, 0, 0, matrix.size(), matrix[0].size(), result);
        return result;
    }

    void spiralOrderCore(vector<vector<int>> &matrix, int m, int n, int row, int col, vector<int> &result) {
        if (row <= 0 || col <= 0)
            return;
        //向右定有
        for (int i = n; i <= n + col - 1; i++) {
            result.push_back(matrix[m][i]);
        }
        //向下需要行大于等于2
        if (row >= 2)
            for (int i = m + 1; i <= m + row - 1; i++) {
                result.push_back(matrix[i][n + col - 1]);
            }
        //向左需要列大于等于2，并且行大于等于2
        if (row >= 2 && col >= 2)
            for (int i = n + col - 2; i >= n; i--) {
                result.push_back(matrix[m + row - 1][i]);
            }
        //向上需要行大于等于三，列大于等于2
        if (row >= 3 && col >= 2)
            for (int i = m + row - 2; i >= m + 1; i--) {
                result.push_back(matrix[i][n]);
            }
        spiralOrderCore(matrix, m + 1, n + 1, row - 2, col - 2, result);
        return;
    }

};