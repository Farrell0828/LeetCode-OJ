/**
 * 21.cpp -- #21 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/merge-two-sorted-lists/description/
 * Author: Farrell Meng
 * Creation Date: 2018-11-14
 * Update Date:   2018-11-14
 * Submission Result: Accepted
 * 
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto p = l1;
        auto q = l2;
        ListNode* new_list = new ListNode(0);
        auto r = new_list;

        while (p != nullptr && q != nullptr) {
            if (p->val <= q->val) {
                r->next = p;
                p = p->next;
            }
            else {
                r->next = q;
                q = q->next;
            }
            r = r->next;
        }

        if (p != nullptr) {
            r->next = p;
        }
        else {
            r->next = q;
        }

        r = new_list;
        new_list = r->next;
        delete r;
        return new_list;
    }
};

void ShowList(const ListNode* l) {
    auto p = l;
    while (p != nullptr) {
        cout << (p->val) << " ";
        p = p->next;
    }
    cout << endl;
}

void DeleteList(ListNode* l) {
    auto head = new ListNode(0);
    head->next = l;
    auto pre = head;
    auto p = l;
    while (p != nullptr) {
        pre->next = p->next;
        delete p;
        p = pre->next;
    }
    delete head;
}

int main() {
    auto l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    ShowList(l1);

    auto l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    ShowList(l2);

    Solution s;
    auto new_list = s.mergeTwoLists(l1, l2);
    ShowList(new_list);
    DeleteList(new_list);

    cin.get();
    return 0;
}