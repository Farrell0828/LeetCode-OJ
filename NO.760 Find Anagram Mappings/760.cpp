/**
* 760.cpp -- #760 of LeetCode OJ
*
* Source: https://leetcode.com/problems/find-anagram-mappings/description/
* Author: Farrell Meng
* Creation Date: 2018-01-11
* Update Date:   2018-01-11
* Submission Result: Accepted
*
* Given two lists Aand B, and B is an anagram of A. B is an anagram of A
* means B is made by randomizing the order of the elements in A.
* We want to find an index mapping P, from A to B. A mapping P[i] = j
* means the ith element in A appears in B at index j.
* These lists A and B may contain duplicates. 
* If there are multiple answers, output any of them.
*
* For example, given
* A = [12, 28, 46, 32, 50]
* B = [50, 12, 32, 46, 28]
*
* We should return
* [1, 4, 3, 2, 0]
*
* as P[0] = 1 because the 0th element of A appears at B[1], and P[1] = 4 
* because the 1st element of A appears at B[4], and so on.
*
* Note:
* 1. A, B have equal lengths in range [1, 100].
* 2. A[i], B[i] are integers in range [0, 10^5].
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
		int len = A.size();
		vector<int> result(len, -1);
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				if (A[i] == B[j]) {
					result[i] = j;
				}
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<int> A = { 12, 28, 46, 32, 50 };
	vector<int> B = { 50, 12, 32, 46, 28 };
	vector<int> result = s.anagramMappings(A, B);
	for (auto x : result) {
		cout << x << ' ';
	}
	return 0;
}