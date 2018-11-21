/**
 * 142.cpp -- #142 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/linked-list-cycle-ii/
 * Author: Farrell Meng
 * Creation Date: 2018-11-21
 * Update Date:   2018-11-21
 * Submission Result: Accepted
 *
 * Given a linked list, return the node where the cycle begins. 
 * If there is no cycle, return null.
 * 
 * Note: Do not modify the linked list.
 * 
 * Follow up:
 * Can you solve it without using extra space?
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};