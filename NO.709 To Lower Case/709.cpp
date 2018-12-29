/**
 * 709.cpp -- #709 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/to-lower-case/
 * Author: Farrell Meng
 * Creation Date: 2018-12-29
 * Update Date:   2018-12-29
 * Submission Result: Accepted
 *
 * Implement function ToLowerCase() that has a string parameter str, 
 * and returns the same string in lowercase.
 * 
 * Example 1:
 * Input: "Hello"
 * Output: "hello"
 * 
 * Example 2:
 * Input: "here"
 * Output: "here"
 * 
 * Example 3:
 * Input: "LOVELY"
 * Output: "lovely"
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        string lower_str = "";
        for (auto x : str) {
            lower_str.push_back(tolower(x));
        }
        return lower_str;
    }
};

int main() {
    string str = "Hello";
    Solution s;
    cout << s.toLowerCase(str);
    cin.get();
    return 0;
}