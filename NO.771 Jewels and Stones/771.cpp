/**
 * 771.cpp -- #771 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/max-increase-to-keep-city-skyline/description/
 * Author: Farrell Meng
 * Creation Date: 2018-04-13
 * Update Date:   2018-04-13
 * Submission Result: Accepted
 * 
 * You're given strings J representing the types of stones that are jewels, 
 * and S representing the stones you have.  Each character in S is a type of stone you have. 
 * You want to know how many of the stones you have are also jewels.
 * 
 * The letters in J are guaranteed distinct, and all characters in J and S are letters. 
 * Letters are case sensitive, so "a" is considered a different type of stone from "A".
 * 
 * Example 1:
 * 
 * Input: J = "aA", S = "aAAbbbb"
 * Output: 3
 * Example 2:
 * 
 * Input: J = "z", S = "ZZ"
 * Output: 0
 * 
 * Note:
 *
 * S and J will consist of letters and have length at most 50.
 * The characters in J are distinct.
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int numJewelsInStones(string J, string S) {
		int count = 0;
		for (auto x : J) {
			for (auto y : S) {
				if (x == y) count++;
			}
		}
		return count;
	}
};

int main() {
	string J = "aA", S = "aAAbbbb";
	Solution s;
	cout << s.numJewelsInStones(J, S) << endl;
	J = "z", S = "ZZ";
	cout << s.numJewelsInStones(J, S) << endl;
	return 0;
}