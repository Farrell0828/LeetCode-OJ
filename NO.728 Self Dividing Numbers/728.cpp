/**
* 728.cpp -- #728 of LeetCode OJ
*
* Source: https://leetcode.com/problems/self-dividing-numbers/description/
* Author: Farrell Meng
* Date:   2018-01-11
*
* A self - dividing number is a number that is divisible by every digit it contains.
* For example, 128 is a self - dividing number 
* because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
* Also, a self - dividing number is not allowed to contain the digit zero.
* Given a lower and upper number bound, output a list of every possible 
* self dividing number, including the bounds if possible.
*
* Example 1:
* Input: left = 1, right = 22
* Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
* 
* Note: The boundaries of each input argument are 1 <= left <= right <= 10000.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isSelfDividingNumbers(int m) {
		int n = m;
		while (n != 0) {
			if (n % 10 == 0 || m % (n % 10) != 0) {
				return false;
			}
			n = n / 10;
		}
		return true;
	}

	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> result;
		for (int i = left; i <= right; i++) {
			if (isSelfDividingNumbers(i)) result.push_back(i);
		}
		return result;
	}
};

int main()
{
	Solution s;
	int left = 1, right = 22;
	vector<int> r = s.selfDividingNumbers(left, right);
	for (auto x : r) {
		cout << x << ' ';
	}
	return 0;
}