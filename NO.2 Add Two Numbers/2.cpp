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

class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		size_t l1_int = ToInt(l1);
		size_t l2_int = ToInt(l2);
		size_t result_int = l1_int + l2_int;
		ListNode *result = ToList(result_int);
		return result;
	}

	// 求链表的节点个数
	size_t Size(ListNode *l)
	{
		size_t n = 1;
		ListNode *p = l;
		while (p->next != NULL)
		{
			n++;
			p = p->next;
		}
		return n;
	}

	// 求整数的位数
	size_t NumOfDigits(size_t n)
	{
		if (n == 0)
		{
			return 1;
		}
		size_t num = 0;
		size_t i = 0;
		while (n / Pow(10, i) != 0)
		{
			num++;
			i++;
		}
		return num;
	}

	// x的y次方
	size_t Pow(size_t x, size_t y)
	{
		size_t n = 1;
		for (int i = 0; i < y; i++)
		{
			n = n * x;
		}
		return n;
	}

	// 将链表转换成整数
	size_t ToInt(ListNode *l)
	{
		size_t size = Size(l);
		size_t value = 0;
		ListNode *p = l;
		for (int i = 0; i < size; i++)
		{
			value += p->val * Pow(10, i);
			p = p->next;
		}
		return value;
	}

	// 将整数转换成链表
	ListNode * ToList(size_t n)
	{
		size_t num = NumOfDigits(n);
		ListNode *last = new ListNode(0);
		ListNode *p = last;

		for (int i = 0; i < num; i++)
		{
			p->val = n / Pow(10, num - i - 1);
			n = n - p->val * Pow(10, num - i - 1);
			ListNode *previous_node = new ListNode(0);
			previous_node->next = p;
			p = previous_node;
		}
		return p->next;
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