/**
 * 872.cpp -- #872 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/leaf-similar-trees/
 * Author: Farrell Meng
 * Creation Date: 2018-08-07
 * Update Date:   2018-08-07
 * Submission Result: Accepted
 * 
 * Consider all the leaves of a binary tree. From left to right order, 
 * the values of those leaves form a leaf value sequence.
 *                    3
 *                   / \
 *                  /   \
 *                 5     1
 *                / \   / \
 *               6   2 9   8
 *                  / \
 *                 7   4
 * For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
 * Two binary trees are considered leaf-similar if their leaf value sequence is the same.
 * Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 * Note:
 * Both of the given trees will have between 1 and 100 nodes.
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1(0);
        vector<int> seq2(0);
        getLeafValueSeq(root1, seq1);
        getLeafValueSeq(root2, seq2);
        return seq1 == seq2;
    }

    void getLeafValueSeq(TreeNode* root, vector<int>& seq) {
        if (root == NULL) {
            return;
        }
        getLeafValueSeq(root->left, seq);
        getLeafValueSeq(root->right, seq);
        if (root->left == NULL && root->right == NULL) {
            seq.push_back(root->val);
        }
    }
};