/**
 * 4.cpp -- #4 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 * Author: Farrell Meng
 * Date:   2018-04-10
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 *
 * The median is 2.0
 *
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> nums3;
		size_t n1 = nums1.size();
		size_t n2 = nums2.size();
		size_t i = 0, j = 0;
		while (i < n1 && j < n2) {
			if (nums1[i] < nums2[j]) {
				nums3.push_back(nums1[i]);
				i++;
			}
			else {
				nums3.push_back(nums2[j]);
				j++;
			}
		}
		while (i < n1) {
			nums3.push_back(nums1[i]);
			i++;
		}
		while (j < n2) {
			nums3.push_back(nums2[j]);
			j++;
		}
		size_t n3 = n1 + n2;
		if (n3 % 2) {
			return double(nums3[n3 / 2]);
		}
		else {
			return double(nums3[n3 / 2] + nums3[(n3 / 2) - 1]) / 2.0;
		}
	}
};

int main() {
	Solution s;
	vector<int> num1 = { 1, 3 };
	vector<int> num2 = { 2 };
	cout << s.findMedianSortedArrays(num1, num2) << endl;
	vector<int> num3 = { 1, 2 };
	vector<int> num4 = { 3, 4 };
	cout << s.findMedianSortedArrays(num3, num4) << endl;
	return 0;
}