/**
 * 203.cpp -- #203 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/remove-linked-list-elements/
 * Author: Farrell Meng
 * Creation Date: 2018-10-31
 * Update Date:   2018-10-31
 * Submission Result: Accepted
 * 
 * Remove all elements from a linked list of integers that have value val.
 * Example:
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 增加一个临时头节点
        auto head_node = new ListNode(0);
        head_node->next = head;

        auto pre = head_node;       // 前驱节点
        auto p = head_node->next;   // 当前节点
        while (p != nullptr) {
            if (p->val == val) {
                pre->next = p->next;
                delete p;
                p = pre->next;
            }
            else {
                pre = p;
                p = p->next;
            }
        }
        head = head_node->next;
        delete head_node;   // 删除增加的临时节点
        return head;
    }
};

void ShowList(const ListNode* head) {
    auto p = head;
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    ShowList(head);
    Solution s;
    head = s.removeElements(head, 6);
    ShowList(head);
    cin.get();
    return 0;
}