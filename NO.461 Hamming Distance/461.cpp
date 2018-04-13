/**
 * 461.cpp -- #461 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/hamming-distance/description/
 * Author: Farrell Meng
 * Creation Date: 2018-01-11
 * Update Date:   2018-01-11
 * Submission Result: Accepted
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 * Given two integers x and y, calculate the Hamming distance.
 *
 * Note: 0 ¡Ü x, y < 2^31.
 *
 * Example:
 * Input: x = 1, y = 4
 * Output: 2
 *
 * Explanation:
 *   1  (0 0 0 1)
 *   4  (0 1 0 0)
 *         ¡ü   ¡ü
 *
 * The above arrows point to positions where the corresponding bits are different.
 */

#include <iostream>
using namespace std;

class Solution {
public:
	int hammingDistance(int x, int y) {
		int z = x ^ y;
		int count = 0;
		while (z) {
			if (z & 1) count++;
			z = z >> 1;
		}
		return count;
	}
};

int main() {
	Solution s;
	int x = 1, y = 4;
	cout << s.hammingDistance(x, y) << endl;
	return 0;
}