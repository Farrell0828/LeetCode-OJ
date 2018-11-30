/**
 * 700.cpp -- #700 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/search-in-a-binary-search-tree/
 * Author: Farrell Meng
 * Creation Date: 2018-11-28
 * Update Date:   2018-11-28
 * Submission Result: Accepted
 *
 * Given the root node of a binary search tree (BST) and a value. 
 * You need to find the node in the BST that the node's value equals the given value. 
 * Return the subtree rooted with that node. If such node doesn't exist, 
 * you should return NULL.
 *
 * For example,
 * 
 * Given the tree:
 *        4
 *       / \
 *      2   7
 *     / \
 *    1   3
 * 
 * And the value to search: 2
 * You should return this subtree:
 * 
 *      2
 *     / \
 *    1   3
 */

#include <iostream>
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val) {
            return root;
        }

        auto ret = searchBST(root->left, val);
        if (ret != nullptr) {
            return ret;
        }
        else {
            return searchBST(root->right, val);
        }
    }
};

// 按层次遍历顺序输出二叉树
void Print(TreeNode* t) {
    queue<TreeNode*> q;
    TreeNode* p = t;
    q.push(p);
    while (!q.empty()) {
        p = q.front();
        if (p) {
            cout << p->val << ' ';
            q.push(p->left);
            q.push(p->right);
        }
        else {
            cout << "null ";
        }
        q.pop();
    }
    cout << endl;
}

int main() {
    // 建立Tree
    TreeNode* t = new TreeNode(4);
    t->left = new TreeNode(2);
    t->right = new TreeNode(7);
    t->left->left = new TreeNode(1);
    t->left->right = new TreeNode(3);
    Print(t);

    int val = 2;

    Solution s;
    auto subt = s.searchBST(t, 2);
    Print(subt);

    cin.get();
    return 0;
}