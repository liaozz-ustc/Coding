//
// Created by 廖洲洲 on 2020/10/6.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //递归法太暴力，超过时间限制，这是因为包含了大量的重复计算
    //因此要使用动态规划呀
    int maxValue(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        return maxValueCore(grid, 0, 0);
    }

    int maxValueCore(vector<vector<int> > &grid, int row, int col) {
        if (row == grid.size() - 1 && col == grid[0].size() - 1)
            return grid[row][col];
        int rightValue = 0;
        int downValue = 0;
        if (row + 1 < grid.size())
            downValue = maxValueCore(grid, row + 1, col);
        if (col + 1 < grid[0].size())
            rightValue = maxValueCore(grid, row, col + 1);
        return downValue > rightValue ? downValue + grid[row][col] : rightValue + grid[row][col];
    }
};

class Solution2 {
public:
    //使用动态规划求解，令f[i][j]表示到达grid[i][j]时所能拿到礼物的最大值
    //故f[i][j]=max(grid[i][j]+f[i+1][j],grid[i][j]+f[i][j+1]),边界特殊考虑
    //故从底至上计算
    int maxValue(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int row = grid.size();
        int col = grid[0].size();
        int **f = (int **) malloc(row * sizeof(int *));
        for (int i = 0; i < row; i++)
            f[i] = (int *) malloc(col * sizeof(int));
        f[row - 1][col - 1] = grid[row - 1][col - 1];
        for (int i = col - 2; i >= 0; i--)
            f[row - 1][i] = f[row - 1][i + 1] + grid[row - 1][i];
        for (int i = row - 2; i >= 0; i--)
            f[i][col - 1] = f[i + 1][col - 1] + grid[i][col - 1];
        for (int i = row - 2; i >= 0; i--)
            for (int j = col - 2; j >= 0; j--) {
                f[i][j] = f[i + 1][j] >= f[i][j + 1] ? grid[i][j] + f[i + 1][j] : grid[i][j] + f[i][j + 1];
            }
        //每次都忘记free数组了,但是free好费时间啊
        int max = f[0][0];
        for(int i=0;i<row;i++)
            free(f[i]);
        free(f);
        return max;
    }
};

class Solution3 {
public:
    //使用动态规划求解，令f[i][j]表示到达grid[i][j]时所能拿到礼物的最大值
    //故f[i][j]=max(grid[i][j]+f[i+1][j],grid[i][j]+f[i][j+1]),边界特殊考虑
    //故从底至上计算
    //再次优化，由于每个格点的计算只与其右边和下边的格点有关，故计算时只需要使用一个一维数组即可
    //右边的直接再格点右边找到，下面的直接由当前位置找到，然后覆盖
    int maxValue(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int row = grid.size();
        int col = grid[0].size();
        int *f=(int *)malloc(col*sizeof(int));
        f[col-1]=grid[row-1][col-1];
        for(int i=col-2;i>=0;i--)
            f[i]=f[i+1]+grid[row-1][i];
        for(int i=row-2;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                if(j==col-1){
                    f[j]=f[j]+grid[i][j];
                }else{
                    f[j]=f[j]>=f[j+1]?f[j]+grid[i][j]:f[j+1]+grid[i][j];
                }
            }
        }
        return f[0];
    }
};