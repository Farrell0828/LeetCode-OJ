/**
 * 104.cpp -- #104 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/maximum-depth-of-binary-tree/
 * Author: Farrell Meng
 * Creation Date: 2018-12-05
 * Update Date:   2018-12-05
 * Submission Result: Accepted
 *
 * Given a binary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest path 
 * from the root node down to the farthest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 *       3
 *      / \
 *     9  20
 *    /  \
 *   15   7
 * 
 * return its depth = 3.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 递归
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    // 迭代
    int maxDepth2(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int depth = 0;      // 当前深度
        int count = 0;      // 当前层节点个数
        queue<TreeNode*> q;
        q.push(root);
        while (true) {
            count = q.size();
            if (count == 0) {
                return depth;
            }
            else {
                depth++;
            }
            while (count != 0) {
                auto x = q.front();
                q.pop();
                if (x->left != nullptr) {
                    q.push(x->left);
                }
                if (x->right != nullptr) {
                    q.push(x->right);
                }
                count--;
            }
        }
    }
};

int main() {
    auto t = new TreeNode(3);
    t->left = new TreeNode(9);
    t->right = new TreeNode(20);
    t->right->left = new TreeNode(15);
    t->right->right = new TreeNode(7);
    Solution s;
    cout << s.maxDepth(t) << endl;
    cout << s.maxDepth2(t) << endl;
    cin.get();
    return 0;
}