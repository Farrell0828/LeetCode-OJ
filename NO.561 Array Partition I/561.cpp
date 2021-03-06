/**
 * 561.cpp -- #561 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/array-partition-i/description/
 * Author: Farrell Meng
 * Creation Date: 2018-01-11
 * Update Date:   2018-01-11
 * Submission Result: Accepted
 *
 * Given an array of 2n integers, your task is to group these integers into
 * n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes
 * sum of min(ai, bi) for all i from 1 to n as large as possible.
 *
 * Example 1:
 * Input: [1,4,3,2]
 *
 * Output: 4
 * Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
 *
 * Note:
 * 1. n is a positive integer, which is in the range of [1, 10000].
 * 2. All the integers in the array will be in the range of [-10000, 10000].
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int sum = 0;
		for (size_t i = 0; i < nums.size(); i = i + 2) {
			sum += nums[i];
		}
		return sum;
	}
};

int main() {
	Solution s;
	vector<int> nums = { 1, 4, 3, 2 };
	cout << s.arrayPairSum(nums) << endl;
	return 0;
}