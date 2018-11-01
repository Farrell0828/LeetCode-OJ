/**
 * 79.cpp -- #79 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/word-search/
 * Author: Farrell Meng
 * Creation Date: 2018-10-31
 * Update Date:   2018-10-31
 * Submission Result: Accepted
 * 
 * Given a 2D board and a word, find if the word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cell, 
 * where "adjacent" cells are those horizontally or vertically neighboring. 
 * The same letter cell may not be used more than once.
 * 
 * Example:
 * board =
 * [
 *   ['A','B','C','E'],
 *   ['S','F','C','S'],
 *   ['A','D','E','E']
 * ]
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        auto m = board.size();      // 行数
        auto n = board[0].size();   // 列数
        vector<vector<int>> used;   // 是否被使用过的标记
        for (size_t i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            used.push_back(temp);
        }
        // 存储需要去进行比较信息的栈
        stack<vector<size_t>> need_to_match;
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                need_to_match.push(vector<size_t>{ i, j, 0 });
            }
        }
        // 存储已经匹配上信息的栈
        stack<vector<size_t>> matched = {};

        while (!need_to_match.empty()) {
            auto t = need_to_match.top();
            need_to_match.pop();
            auto i = t[0];
            auto j = t[1];
            auto k = t[2];
            // 清除已经过时的信息
            while (!matched.empty() && matched.top()[2] >= k) {
                used[matched.top()[0]][matched.top()[1]] = 0;
                matched.pop();
            }
            // 如果当前匹配上
            if (board[i][j] == word[k]) {
                // 已经匹配到最后一个，表明全部匹配成功
                if (k == word.size() - 1) {
                    return true;
                }
                // 将当前的匹配信息记录
                matched.push(vector<size_t>{ i, j, k });
                used[i][j] = 1;

                // 检查左邻居
                if (j > 0 && !(used[i][j - 1])) {
                    need_to_match.push(vector<size_t>{ i, j - 1, k + 1});
                }
                // 检查下邻居
                if (i + 1 < m && !used[i + 1][j]) {
                    need_to_match.push(vector<size_t>{ i + 1, j, k + 1 });
                }
                // 检查右邻居
                if (j + 1 < n && !used[i][j + 1]) {
                    need_to_match.push(vector<size_t>{ i, j + 1, k + 1 });
                }
                // 检查上邻居
                if (i > 0 && !used[i - 1][j]) {
                    need_to_match.push(vector<size_t>{ i - 1, j, k + 1 });
                }
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board = {
        { 'A', 'B', 'C', 'E' },
        { 'S', 'F', 'C', 'S' },
        { 'A', 'D', 'E', 'E' }
    };

    string word1 = "ABCCED";
    string word2 = "SEE";
    string word3 = "ABCB";

    Solution s;
    bool result = s.exist(board, word1);
    cout << (s.exist(board, word1) ? "True\n" : "False\n");
    cout << (s.exist(board, word2) ? "True\n" : "False\n");
    cout << (s.exist(board, word3) ? "True\n" : "False\n");

    cin.get();
    return 0;
}