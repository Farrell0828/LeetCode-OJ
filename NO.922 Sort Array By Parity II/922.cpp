/**
 * 922.cpp -- #922 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/sort-array-by-parity-ii/
 * Author: Farrell Meng
 * Creation Date: 2018-12-31
 * Update Date:   2018-12-31
 * Submission Result: Accepted
 *
 * Given an array A of non-negative integers, half of the integers in A are odd, 
 * and half of the integers are even.
 * 
 * Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, 
 * i is even.
 * 
 * You may return any answer array that satisfies this condition.
 * 
 * Example 1:
 *   Input: [4,2,5,7]
 *   Output: [4,5,2,7]
 *   Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
 *
 * Note:
 *   2 <= A.length <= 20000
 *   A.length % 2 == 0
 *   0 <= A[i] <= 1000
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        size_t odd = 1;
        size_t even = 0;
        while (odd < A.size() && even < A.size()) {
            while (odd < A.size() && A[odd] % 2 == 1) {
                odd += 2;
            }
            while (even < A.size() && A[even] % 2 == 0) {
                even += 2;
            }
            if (odd < A.size() && even < A.size()) {
                swap(A[odd], A[even]);
            }
        }
        return A;
    }
};

void ShowVector(const vector<int>& A) {
    for (auto x : A) {
        cout << x << ' ';
    }
}

int main() {
    vector<int> A = { 4, 2, 5, 7 };
    Solution s;
    ShowVector(s.sortArrayByParityII(A));
    cin.get();
    return 0;
}