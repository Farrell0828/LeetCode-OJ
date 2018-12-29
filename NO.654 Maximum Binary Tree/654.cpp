/**
 * 654.cpp -- #654 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/maximum-binary-tree/
 * Author: Farrell Meng
 * Creation Date: 2018-12-05
 * Update Date:   2018-12-05
 * Submission Result: Accepted
 *
 * Given an integer array with no duplicates. 
 * A maximum tree building on this array is defined as follow:
 * 
 * The root is the maximum number in the array.
 * The left subtree is the maximum tree constructed from left part subarray 
 * divided by the maximum number.
 * The right subtree is the maximum tree constructed from right part subarray 
 * divided by the maximum number.
 * Construct the maximum tree by the given array and output the root node of this tree.
 *
 * Example 1:
 * Input: [3,2,1,6,0,5]
 * Output: return the tree root node representing the following tree:
 *
 *     6
 *   /   \
 *  3     5
 *   \   / 
 *    2 0   
 *     \
 *      1
 * 
 * Note:
 * The size of the given array will be in the range [1,1000].
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        auto max = max_element(nums.begin(), nums.end());
        if (max == nums.end()) {
            return nullptr;
        }
        auto tree = new TreeNode(*max);
        vector<int> left_sub(nums.begin(), max);
        vector<int> right_sub(++max, nums.end());
        tree->left = constructMaximumBinaryTree(left_sub);
        tree->right = constructMaximumBinaryTree(right_sub);
        return tree;
    }
};

// 按层次遍历顺序输出二叉树
void PrintTree(TreeNode* t) {
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
    vector<int> nums = { 3, 2, 1, 6, 0, 5 };
    Solution s;
    auto tree = s.constructMaximumBinaryTree(nums);
    PrintTree(tree);

    cin.get();
    return 0;
}