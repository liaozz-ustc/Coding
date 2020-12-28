//
// Created by 廖洲洲 on 2020/10/2.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int movingCount(int m, int n, int k) {
        if (m <= 0 || n <= 0)
            return 0;
        if (k == 0)
            return 1;
        bool **visited;
        visited = (bool **) malloc(m * sizeof(bool *));
        for (int i = 0; i < m; i++)
            visited[i] = (bool *) malloc(n * sizeof(bool));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                visited[i][j] = false;
        moving(m, n, k, 0, 0, visited);
        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (visited[i][j])
                    count++;
        for(int i=0;i<m;i++)
            free(visited[i]);
        free(visited);
        return count;
    }

    void moving(int m, int n, int k, int row, int col, bool **visited) {
        visited[row][col] = true;
        int newRow, newCol;
        newRow = row + 1;
        newCol = col;
        if (newRow < m && check(newRow, newCol, k) && !visited[newRow][newCol]) {
            moving(m, n, k, newRow, newCol, visited);
        }
        newRow = row - 1;
        newCol = col;
        if (newRow>=0  && check(newRow, newCol, k) && !visited[newRow][newCol]) {
            moving(m, n, k, newRow, newCol, visited);
        }
        newRow = row;
        newCol = col + 1;
        if (newCol < n && check(newRow, newCol, k) && !visited[newRow][newCol]) {
            moving(m, n, k, newRow, newCol, visited);
        }
        newRow = row;
        newCol = col - 1;
        if (newCol >=0 && check(newRow, newCol, k) && !visited[newRow][newCol]) {
            moving(m, n, k, newRow, newCol, visited);
        }
        return;
    }

    bool check(int row, int col, int k) {
        int tmp = 0;
        while (row) {
            tmp += row % 10;
            row = row / 10;
        }
        while (col) {
            tmp += col % 10;
            col = col / 10;
        }
        if (tmp <= k)
            return true;
        return false;
    }
};