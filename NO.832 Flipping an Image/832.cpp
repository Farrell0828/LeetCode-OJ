/**
 * 832.cpp -- #832 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/flipping-an-image/
 * Author: Farrell Meng
 * Creation Date: 2018-12-29
 * Update Date:   2018-12-29
 * Submission Result: Accepted
 *
 * Given a binary matrix A, we want to flip the image horizontally, 
 * then invert it, and return the resulting image.
 *
 * To flip an image horizontally means that each row of the image is reversed.  
 * For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].
 *
 * To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. 
 * For example, inverting [0, 1, 1] results in [1, 0, 0].
 * 
 * Example 1:
 * Input: [[1,1,0],[1,0,1],[0,0,0]]
 * Output: [[1,0,0],[0,1,0],[1,1,1]]
 * Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
 *              Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
 * Example 2:
 * Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
 * Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 * Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
 *              Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 * Notes:
 *   1 <= A.length = A[0].length <= 20
 *   0 <= A[i][j] <= 1
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        auto row_num = A.size();
        auto col_num = A[0].size();
        auto A_new = A;
        for (size_t i = 0; i < row_num; i++) {
            for (size_t j = 0; j < col_num; j++) {
                if (A[i][col_num - j - 1] == 0) {
                    A_new[i][j] = 1;
                }
                else {
                    A_new[i][j] = 0;
                }
            }
        }
        return A_new;
    }
};

void ShowMatrix(const vector<vector<int>>& A) {
    for (auto x : A) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {
        { 1, 1, 0, 0 },
        { 1, 0, 0, 1 },
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 }
    };
    Solution s;
    ShowMatrix(s.flipAndInvertImage(A));
    cin.get();
    return 0;
}