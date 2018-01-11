/**
 * 617.cpp -- #617 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/merge-two-binary-trees/description/
 * Author: Farrell Meng
 * Date:   2018-01-11
 *
 * Given two binary trees and imagine that when you put one of them to cover
 * the other, some nodes of the two trees are overlapped while the others are not.
 *
 * You need to merge them into a new binary tree.The merge rule is that if
 * two nodes overlap, then sum node values up as the new value of the merged node.
 * Otherwise, the NOT null node will be used as the node of new tree.
 *
 * Example 1:
 * Input:
 *     Tree 1                     Tree 2
 *       1                          2
 *      / \                        / \
 *     3   2                      1   3
 *    /                            \   \
 *   5                              4   7
 * Output:
 *  Merged tree
 *       3
 *      / \
 *     4   5
 *    / \   \
 *   5   4   7
 * Note: The merging process must start from the root nodes of both trees.
 */

#include <iostream>
#include <queue>
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
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == NULL && t2 == NULL) {
			return NULL;
		}
		else if (t1 == NULL && t2 != NULL) {
			return t2;
		}
		else if (t1 != NULL && t2 == NULL) {
			return t1;
		}
		else {
			t1->val = t1->val + t2->val;
			t1->left = mergeTrees(t1->left, t2->left);
			t1->right = mergeTrees(t1->right, t2->right);
			return t1;
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
			cout << "NULL ";
		}
		q.pop();
	}
	cout << endl;
}

int main() {
	// 建立Tree1
	TreeNode* t1 = new TreeNode(1);
	t1->left = new TreeNode(3);
	t1->right = new TreeNode(2);
	t1->left->left = new TreeNode(5);
	Print(t1);

	// 建立Tree2
	TreeNode* t2 = new TreeNode(2);
	t2->left = new TreeNode(1);
	t2->right = new TreeNode(3);
	t2->left->right = new TreeNode(4);
	t2->right->right = new TreeNode(7);
	Print(t2);

	// 合并Tree2与Tree1
	Solution s;
	TreeNode* result = s.mergeTrees(t1, t2);
	Print(result);

	return 0;
}