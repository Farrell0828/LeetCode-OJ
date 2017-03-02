/**
 * 1.cpp -- #1 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/two-sum/?tab=Description
 * Author: Farrell Meng
 * Date:   2017-03-03
 *
 * Given an array of integers, return indices of the two numbers such
 * that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and
 * you may not use the same element twice.
 *
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */ 

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> result;
		for (int i = 0; i < (int)nums.size(); i++)
		{
			for (int j = i + 1; j < (int)nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					result.push_back(i);
					result.push_back(j);
				}
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;
	vector<int> result = s.twoSum(nums, target);
	for (auto x : result)
	{
		cout << x << " ";
	}
	cout << endl;
	cin.get();
	return 0;
}