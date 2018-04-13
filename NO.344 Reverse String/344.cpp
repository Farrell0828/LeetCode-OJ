/**
 * 344.cpp -- #344 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/reverse-string/description/
 * Author: Farrell Meng
 * Creation Date: 2018-01-11
 * Update Date:   2018-01-11
 * Submission Result: Accepted
 *
 * Write a function that takes a string as input and returns the string reversed.
 *
 * Example:
 * Given s = "hello", return "olleh".
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string reverseString(string s) {
		if (s.empty() || s.length() == 1) {
			return s;
		}
		auto temp = s[0];
		auto len = s.length();
		for (int i = 0; i < len / 2; i++) {
			temp = s[i];
			s[i] = s[len - i - 1];
			s[len - i - 1] = temp;
		}
		return s;
	}
};

int main()
{
	Solution s;
	string s1 = "hello";
	string s2 = s.reverseString(s1);
	cout << s2 << endl;
	return 0;
}