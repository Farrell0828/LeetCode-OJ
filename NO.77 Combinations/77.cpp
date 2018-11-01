/**
 * 77.cpp -- #77 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/combinations/
 * Author: Farrell Meng
 * Creation Date: 2018-10-17
 * Update Date:   2018-10-17
 * Submission Result: Accepted
 *
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 * Example:
 * Input: n = 4, k = 2
 * Output:
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 */

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> Combine(int n, int k) {
    vector<vector<int>> result;
    if (k == 1) {
        for (int i = 1; i <= n; i++) {
            result.push_back(vector<int> { i });
        }
    }
    else if (k == n) {
        vector<int> temp;
        for (int i = 1; i <= n; i++) {
            temp.push_back(i);
        }
        result.push_back(temp);
    }
    else {
        result = Combine(n - 1, k);
        auto second = Combine(n - 1, k - 1);
        for (auto i = second.begin(); i != second.end(); i++) {
            (*i).push_back(n);
        }
        result.insert(result.end(), second.begin(), second.end());
    }
    return result;
}

void PrintMatrix(vector<vector<int>> m) {
    cout << "[\n";
    for (auto x : m) {
        cout << "    [";
        for (int i = 0; i < x.size() - 1; i++) {
            cout << x[i] << ", ";
        }
        cout << x[x.size() - 1];
        cout << "],\n";
    }
    cout << "]\n";
}

int main() {
    int n, k;
    cin >> n >> k;
    auto x = Combine(n, k);
    PrintMatrix(x);
    cin.get();
    cin.get();
    return 0;
}