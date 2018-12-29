/**
 * 905.cpp -- #905 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/sort-array-by-parity/
 * Author: Farrell Meng
 * Creation Date: 2018-12-29
 * Update Date:   2018-12-29
 * Submission Result: Accepted
 *
 * Given an array A of non-negative integers, return an array consisting of all the 
 * even elements of A, followed by all the odd elements of A.
 * 
 * You may return any answer array that satisfies this condition.
 * 
 * Example 1:
 * Input: [3,1,2,4]
 * Output: [2,4,3,1]
 * The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 * 
 * Note:
 *   1 <= A.length <= 5000
 *   0 <= A[i] <= 5000
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        auto it_even = A.begin();
        auto it_odd = A.end() - 1;
        while (it_even < it_odd) {
            while (*it_even % 2 == 0) {
                it_even++;
            }
            while (*it_odd % 2 == 1) {
                it_odd--;
            }
            if (it_even < it_odd) {
                swap(*it_even, *it_odd);
            }
        }
        return A;
    }
};

void ShowVector(vector<int> A) {
    for (auto x : A) {
        cout << x << " ";
    }
}

int main() {
    vector<int> A = { 3, 1, 2, 4 };
    Solution s;
    ShowVector(s.sortArrayByParity(A));
    cin.get();
    return 0;
}