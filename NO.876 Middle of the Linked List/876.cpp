/**
 * 876.cpp -- #876 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/middle-of-the-linked-list/
 * Author: Farrell Meng
 * Creation Date: 2018-08-07
 * Update Date:   2018-08-07
 * Submission Result: Accepted
 * 
 * Given a non-empty, singly linked list with head node head, 
 * return a middle node of linked list.
 * If there are two middle nodes, return the second middle node.
 * 
 * Example 1:
 * Input: [1,2,3,4,5]
 * Output: Node 3 from this list (Serialization: [3,4,5])
 * The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
 * Note that we returned a ListNode object ans, such that:
 * ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
 * Example 2:
 * Input: [1,2,3,4,5,6]
 * Output: Node 4 from this list (Serialization: [4,5,6])
 * Since the list has two middle nodes with values 3 and 4, we return the second one.
 * 
 * Note:
 * The number of nodes in the given list will be between 1 and 100.
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
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        auto p = head;
        while (p != nullptr) {
            count++;
            p = p->next;
        }
        int mid = count / 2;
        p = head;
        for (int i = 0; i < mid; i++) {
            p = p->next;
        }
        return p;
    }

    ListNode* middleNode2(ListNode* head) {
        auto p = head;
        auto mid = head;
        bool is_even = false;
        while (p != nullptr) {
            if (is_even) {
                mid = mid->next;
            }
            p = p->next;
            is_even = !is_even;
        }
        return mid;
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
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);
    ShowList(l1);

    Solution s;
    auto mid1 = s.middleNode(l1);
    ShowList(mid1);
    auto mid12 = s.middleNode2(l1);
    ShowList(mid12);
    DeleteList(l1);

    auto l2 = new ListNode(1);
    l2->next = new ListNode(2);
    l2->next->next = new ListNode(3);
    l2->next->next->next = new ListNode(4);
    l2->next->next->next->next = new ListNode(5);
    l2->next->next->next->next->next = new ListNode(6);
    ShowList(l2);

    auto mid2 = s.middleNode(l2);
    ShowList(mid2);
    auto mid22 = s.middleNode2(l2);
    ShowList(mid22);
    DeleteList(l2);

    cin.get();
    return 0;
}