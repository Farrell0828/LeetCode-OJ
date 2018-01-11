/**
 * 476.cpp -- #476 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/number-complement/description/
 * Author: Farrell Meng
 * Date:   2018-01-11
 *
 * Given a positive integer, output its complement number. The complement
 * strategy is to flip the bits of its binary representation.
 *
 * Note:
 * The given integer is guaranteed to fit within the range of a 32-bit signed integer.
 * You could assume no leading zero bit in the integer¡¯s binary representation.
 *
 * Example 1:
 * Input: 5
 * Output: 2
 * Explanation: The binary representation of 5 is 101 (no leading zero bits),
 * and its complement is 010. So you need to output 2.
 *
 * Example 2:
 * Input: 1
 * Output: 0
 * Explanation: The binary representation of 1 is 1 (no leading zero bits),
 * and its complement is 0. So you need to output 0.
 */

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
	int findComplement(int num) {
		stack<int> s;
		while (num) {
			if (num % 2) {
				s.push(1);
			}
			else {
				s.push(0);
			}
			num = num / 2;
		}
		int i = s.size();
		int result = 0;
		while (!s.empty()) {
			if (!s.top()) {
				result += pow(2, i - 1);
			}
			i--;
			s.pop();
		}
		return result;
	}
};

int main() {
	Solution s;
	cout << s.findComplement(5) << endl;
	cout << s.findComplement(1) << endl;
	return 0;
}