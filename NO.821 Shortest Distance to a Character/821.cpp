/**
 * 821.cpp -- #821 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/shortest-distance-to-a-character/
 * Author: Farrell Meng
 * Creation Date: 2019-01-19
 * Update Date:   2019-01-19
 * Submission Result: Accepted
 *
 * Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.
 * 
 * Example 1:
 * Input: S = "loveleetcode", C = 'e'
 * Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 * 
 * Note:
 * S string length is in [1, 10000].
 * C is a single character, and guaranteed to be in string S.
 * All letters in S and C are lowercase.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> c_indexs;
        vector<int> shortestDistances(S.size());
        for (int i = 0; i < S.size(); i++) {
            if (C == S[i]) {
                c_indexs.push_back(i);
            }
        }
        vector<int> distances(c_indexs.size());
        for (int i = 0; i < S.size(); i++) {
            for (int j = 0; j < c_indexs.size(); j++) {
                distances[j] = abs(i - c_indexs[j]);
            }
            shortestDistances[i] = *min_element(distances.begin(), distances.end());
        }
        return shortestDistances;
    }
};

template<typename T>
void ShowVector(const vector<T>& v) {
    for (auto x : v) {
        cout << x << ' ';
    }
    cout << endl;
}

int main() {
    string S = "loveleetcode";
    char C = 'e';
    Solution s;
    ShowVector(s.shortestToChar(S, C));

    cin.get();
    return 0;
}