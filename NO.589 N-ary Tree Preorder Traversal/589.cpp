/**
 * 589.cpp -- #589 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/n-ary-tree-preorder-traversal/
 * Author: Farrell Meng
 * Creation Date: 2018-12-31
 * Update Date:   2018-12-31
 * Submission Result: Accepted
 *
 * Given an n-ary tree, return the preorder traversal of its nodes' values.
 * 
 * For example, given a 3-ary tree:
 *               1
 *              /|\
 *             3 2 4
 *            / \
 *           5   6
 * Return its preorder traversal as: [1,3,5,6,2,4].
 * 
 * Note:
 *   Recursive solution is trivial, could you do it iteratively?
 */

#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (root != nullptr) {
            result.push_back(root->val);
            for (auto x : root->children) {
                auto child_result = preorder(x);
                result.insert(result.end(), child_result.begin(), child_result.end());
            }
        }
        return result;
    }
};

void ShowVector(const vector<int>& v) {
    for (auto x : v) {
        cout << x << ' ';
    }
}

int main() {
    auto n5 = new Node(5, vector<Node*> {});
    auto n6 = new Node(6, vector<Node*> {});
    auto n3 = new Node(3, vector<Node*> { n5, n6 });
    auto n2 = new Node(2, vector<Node*> {});
    auto n4 = new Node(4, vector<Node*> {});
    auto n1 = new Node(1, vector<Node*> { n3, n2, n4 });

    Solution s;
    ShowVector(s.preorder(n1));

    cin.get();
    return 0;
}