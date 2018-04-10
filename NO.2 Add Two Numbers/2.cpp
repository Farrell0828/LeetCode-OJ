/**
 * 2.cpp -- #2 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/add-two-numbers/?tab=Description
 * Author: Farrell Meng
 * Date:   2017-03-03
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.

 * You may assume the two numbers do not contain any leading zero, except the 
 * number 0 itself.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		ListNode* q = NULL;
		ListNode* result = NULL;
		int carry = 0;
		bool first = true;
		while (p1 && p2) {
			int sum = p1->val + p2->val + carry;
			if (first) {
				q = new ListNode(sum % 10);
				result = q;
				first = false;
			}
			else {
				q->next = new ListNode(sum % 10);
				q = q->next;
			}
			carry = sum / 10;
			p1 = p1->next;
			p2 = p2->next;
		}
		while (p1) {
			int sum = p1->val + carry;
			if (first) {
				q = new ListNode(sum % 10);
				result = q;
				first = false;
			}
			else {
				q->next = new ListNode(sum % 10);
				q = q->next;
			}
			carry = sum / 10;
			p1 = p1->next;
		}
		while (p2) {
			int sum = p2->val + carry;
			if (first) {
				q = new ListNode(sum % 10);
				result = q;
				first = false;
			}
			else {
				q->next = new ListNode(sum % 10);
				q = q->next;
			}
			carry = sum / 10;
			p2 = p2->next;
		}
		if (carry) {
			q->next = new ListNode(carry);
		}
		return result;
	}
};

int main()
{
	ListNode *l1 = new ListNode(0);
	l1->val = 2;
	l1->next = new ListNode(0);
	l1->next->val = 4;
	l1->next->next = new ListNode(0);
	l1->next->next->val = 3;
	l1->next->next->next = NULL;

	ListNode *l2 = new ListNode(0);
	l2->val = 5;
	l2->next = new ListNode(0);
	l2->next->val = 6;
	l2->next->next = new ListNode(0);
	l2->next->next->val = 4;
	l2->next->next->next = NULL;

	Solution s;
	ListNode *result = s.addTwoNumbers(l1, l2);
	ListNode *p = result;
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}