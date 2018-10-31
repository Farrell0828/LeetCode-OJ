/**
 * 73.cpp -- #73 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/set-matrix-zeroes/
 * Author: Farrell Meng
 * Creation Date: 2018-10-24
 * Update Date:   2018-10-24
 * Submission Result: Accepted
 * 
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. 
 * Do it in-place.
 * 
 * Example 1:
 * Input: 
 * [
 *   [1,1,1],
 *   [1,0,1],
 *   [1,1,1]
 * ]
 * Output: 
 * [
 *   [1,0,1],
 *   [0,0,0],
 *   [1,0,1]
 * ]
 * 
 * Example 2:
 * 
 * Input: 
 * [
 *   [0,1,2,0],
 *   [3,4,5,2],
 *   [1,3,1,5]
 * ]
 * Output: 
 * [
 *   [0,0,0,0],
 *   [0,4,5,0],
 *   [0,3,1,0]
 * ]
 * Follow up:
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        auto m = matrix.size();
        auto n = matrix[0].size();

        auto first_col_have_zero = false;
        for (size_t i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                first_col_have_zero = true;
                break;
            }
        }

        auto first_row_have_zero = false;
        for (size_t j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                first_row_have_zero = true;
                break;
            }
        }

        for (size_t i = 1; i < m; i++) {
            for (size_t j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (size_t i = 1; i < m; i++) {
            for (size_t j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (first_col_have_zero) {
            for (size_t i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }

        if (first_row_have_zero) {
            for (size_t j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};

void ShowMat(const vector<vector<int>> mat) {
    for (auto x : mat) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    vector<vector<int>> mat = {
        { 1, 1, 1 },
        { 1, 0, 1 },
        { 1, 1, 1 }
    };

    ShowMat(mat);
    Solution s;
    s.setZeroes(mat);
    ShowMat(mat);
    
    cin.get();
    return 0;
}