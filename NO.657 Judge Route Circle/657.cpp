/**
 * 657.cpp -- #657 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/judge-route-circle/description/
 * Author: Farrell Meng
 * Date:   2018-01-11
 *
 * Initially, there is a Robot at position (0, 0). Given a sequence of its
 * moves, judge if this robot makes a circle, which means it moves back to
 * the original place.
 *
 * The move sequence is represented by a string. And each move is represent
 * by a character. The valid robot moves are R (Right), L (Left), U (Up) 
 * and D (down). The output should be true or false representing whether
 * the robot makes a circle.
 *
 * Example 1:
 * Input: "UD"
 * Output: true

 * Example 2:
 * Input: "LL"
 * Output: false
 */

#include <iostream>
using namespace std;

class Solution {
public:
	bool judgeCircle(string moves) {
		int count_u = 0;
		int count_d = 0;
		int count_l = 0;
		int count_r = 0;
		for (auto x : moves) {
			switch (x) {
				case 'U': count_u++; break;
				case 'D': count_d++; break;
				case 'L': count_l++; break;
				case 'R': count_r++; break;
				default: break;
			}
		}
		if (count_u == count_d && count_l == count_r) return true;
		else return false;
	}
};

int main() {
	Solution s;
	string input1 = "UD";
	if (s.judgeCircle(input1)) cout << "true";
	else cout << "false";
	cout << endl;
	string input2 = "LL";
	if (s.judgeCircle(input2)) cout << "true";
	else cout << "false";
	cout << endl;
	return 0;
}