/**
 * 965.cpp -- #965 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/univalued-binary-tree/
 * Author: Farrell Meng
 * Creation Date: 2018-12-30
 * Update Date:   2018-12-30
 * Submission Result: Accepted
 *
 * A binary tree is univalued if every node in the tree has the same value.
 * 
 * Return true if and only if the given tree is univalued.
 *
 * Example 1:
 *            1
 *           / \
 *          1   1
 *         / \   \
 *        1   1   1
 *
 * Example 2:
 *            2
 *           / \
 *          2   2
 *         / \
 *        2   2
 */

#include <iostream>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        return inOrder(root, root->val);
    }

    bool inOrder(TreeNode* root, int val) {
        if (root == nullptr) {
            return true;
        }
        return (root->val == val) &&
            inOrder(root->left, val) &&
            inOrder(root->right, val);
    }
};

int main() {
    auto t = new TreeNode(2);
    t->left = new TreeNode(2);
    t->right = new TreeNode(2);
    t->left->left = new TreeNode(2);
    t->left->right = new TreeNode(2);
    Solution s;
    cout << (s.isUnivalTree(t) ? "true" : "false");
    cin.get();
    return 0;
}