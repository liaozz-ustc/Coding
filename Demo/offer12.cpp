//
// Created by 廖洲洲 on 2020/10/2.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        if (board.empty() || board[0].empty())
            return false;
        if (word.length() == 0)
            return true;
        bool **visited = (bool **) malloc(board.size() * sizeof(bool *));//判断该格子是否已经走过
        for (int i = 0; i < board.size(); i++)
            visited[i] = (bool *) malloc(board[0].size() * sizeof(bool));
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                visited[i][j] = false;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j ++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (word.length() == 1 || findPath(board, word.substr(1, word.length() - 1), visited, i, j))
                        return true;
                    visited[i][j] = false;
                }
            }
        return false;
    }

    bool findPath(vector<vector<char>> &board, string word, bool **visited, int row, int col) {
        if (word.length() == 1) {
            if ((row - 1 >= 0 && !visited[row - 1][col] && word[0] == board[row - 1][col]) ||
                (row + 1 < board.size() && !visited[row + 1][col] && word[0] == board[row + 1][col]) ||
                (col - 1 >= 0 && !visited[row][col - 1] && word[0] == board[row][col - 1]) ||
                (col + 1 < board[0].size() && !visited[row][col + 1] && word[0] == board[row][col + 1])
                    )
                return true;
        }
        if ((row - 1 >= 0 && !visited[row - 1][col] && word[0] == board[row - 1][col])) {
            visited[row - 1][col] = true;
            if (findPath(board, word.substr(1, word.length() - 1), visited, row - 1, col))
                return true;
            visited[row - 1][col] = false;
        }
        if ((row + 1 < board.size() && !visited[row + 1][col] && word[0] == board[row + 1][col])) {
            visited[row +1][col] = true;
            if (findPath(board, word.substr(1, word.length() - 1), visited, row +1, col))
                return true;
            visited[row + 1][col] = false;
        }
        if ((col - 1 >= 0 && !visited[row][col - 1] && word[0] == board[row][col - 1])) {
            visited[row ][col-1] = true;
            if (findPath(board, word.substr(1, word.length() - 1), visited, row , col-1))
                return true;
            visited[row ][col-1] = false;
        }
        if ((col + 1 < board[0].size() && !visited[row][col + 1] && word[0] == board[row][col + 1])) {
            visited[row ][col+1] = true;
            if (findPath(board, word.substr(1, word.length() - 1), visited, row , col+1))
                return true;
            visited[row][col + 1] = false;
        }
        return false;
    }
};