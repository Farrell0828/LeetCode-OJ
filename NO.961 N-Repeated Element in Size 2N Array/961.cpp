/**
 * 961.cpp -- #961 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
 * Author: Farrell Meng
 * Creation Date: 2018-12-29
 * Update Date:   2018-12-29
 * Submission Result: Accepted
 *
 * In a array A of size 2N, there are N+1 unique elements, 
 * and exactly one of these elements is repeated N times.
 *
 * Return the element repeated N times.
 *
 * Example 1:
 * Input: [1,2,3,3]
 * Output: 3
 * 
 * Example 2:
 * Input: [2,1,2,5,3,2]
 * Output: 2
 * 
 * Example 3:
 * Input: [5,1,5,2,5,3,5,4]
 * Output: 5
 * 
 * Note:
 *   4 <= A.length <= 10000
 *   0 <= A[i] < 10000
 *   A.length is even
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (auto it = A.begin(); it != A.end(); it++) {
            if (find(it + 1, A.end(), *it) != A.end()) {
                return *it;
            }
        }
    }
};

int main() {
    vector<int> A = { 1, 2, 3, 3 };
    Solution s;
    cout << s.repeatedNTimes(A);
    cin.get();
    return 0;
}