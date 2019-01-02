/**
 * 867.cpp -- #867 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/transpose-matrix/
 * Author: Farrell Meng
 * Creation Date: 2019-01-02
 * Update Date:   2019-01-02
 * Submission Result: Accepted
 *
 * Given a matrix A, return the transpose of A.
 * 
 * The transpose of a matrix is the matrix flipped over it's main diagonal, 
 * switching the row and column indices of the matrix.
 *
 * Example 1:
 *   Input: [[1,2,3],[4,5,6],[7,8,9]]
 *   Output: [[1,4,7],[2,5,8],[3,6,9]]
 * 
 * Example 2:
 *   Input: [[1,2,3],[4,5,6]]
 *   Output: [[1,4],[2,5],[3,6]]
 * 
 * Note:
 *  1 <= A.length <= 1000
 *  1 <= A[0].length <= 1000
 */

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        auto m = A.size();
        auto n = A[0].size();
        vector<vector<int>> B(n, vector<int>(m));
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                B[j][i] = A[i][j];
            }
        }
        return B;
    }
};

void ShowMatrix(const vector<vector<int>>& A) {
    for (auto x : A) {
        for (auto y : x) {
            cout << y << ' ';
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    Solution s;
    ShowMatrix(s.transpose(A));
    cin.get();
    return 0;
}