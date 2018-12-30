/**
 * 852.cpp -- #852 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/peak-index-in-a-mountain-array/
 * Author: Farrell Meng
 * Creation Date: 2018-12-30
 * Update Date:   2018-12-30
 * Submission Result: Accepted
 * 
 * Let's call an array A a mountain if the following properties hold:
 * A.length >= 3
 * There exists some 0 < i < A.length - 1 such that 
 * A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
 * Given an array that is definitely a mountain, return any i such that 
 * A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].
 * 
 * Example 1:
 *   Input: [0,1,0]
 *   Output: 1
 * 
 * Example 2:
 *   Input: [0,2,1,0]
 *   Output: 1
 * 
 * Note:
 *   3 <= A.length <= 10000
 *   0 <= A[i] <= 10^6
 *   A is a mountain, as defined above.
 */

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        size_t left = 0;
        size_t right = A.size() - 1;
        while (left <= right) {
            auto mid = (left + right) / 2;
            if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) {
                return mid;
            }
            else if (A[mid] > A[mid - 1] && A[mid] < A[mid + 1]) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
    }
};

int main() {
    vector<int> A = { 0, 1, 0 };
    Solution s;
    cout << s.peakIndexInMountainArray(A);
    cin.get();
    return 0;
}