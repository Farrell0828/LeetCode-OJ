/**
 * 942.cpp -- #942 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/di-string-match/
 * Author: Farrell Meng
 * Creation Date: 2018-12-30
 * Update Date:   2018-12-30
 * Submission Result: Accepted
 *
 * Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.
 * 
 * Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:
 *   If S[i] == "I", then A[i] < A[i+1]
 *   If S[i] == "D", then A[i] > A[i+1]
 * 
 * Example 1:
 * Input: "IDID"
 * Output: [0,4,1,3,2]
 * 
 * Example 2:
 * Input: "III"
 * Output: [0,1,2,3]
 * 
 * Example 3:
 * Input: "DDI"
 * Output: [3,2,0,1]
 * 
 * Note:
 *   1 <= S.length <= 10000
 *   S only contains characters "I" or "D".
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> result;
        int min = 0;
        int max = S.size();
        for (size_t i = 0; i < S.size(); i++) {
            if (S[i] == 'I') {
                result.push_back(min++);
            }
            else {
                result.push_back(max--);
            }
        }
        result.push_back(min);
        return result;
    }
};

void ShowVector(vector<int> v) {
    for (auto x : v) {
        cout << x << " ";
    }
}

int main() {
    string S = "IDID";
    Solution s;
    ShowVector(s.diStringMatch(S));
    cin.get();
    return 0;
}