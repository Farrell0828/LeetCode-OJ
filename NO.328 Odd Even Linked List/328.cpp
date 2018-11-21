/**
 * 328.cpp -- #328 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/odd-even-linked-list/
 * Author: Farrell Meng
 * Creation Date: 2018-11-21
 * Update Date:   2018-11-21
 * Submission Result: Accepted
 * 
 * Given a singly linked list, group all odd nodes together followed by the even nodes. 
 * Please note here we are talking about the node number and not the value in the nodes.
 * 
 * You should try to do it in place. 
 * The program should run in O(1) space complexity and O(nodes) time complexity.
 * 
 * Example 1:
 * Input: 1->2->3->4->5->NULL
 * Output: 1->3->5->2->4->NULL
 * 
 * Example 2:
 * Input: 2->1->3->5->6->4->7->NULL
 * Output: 2->3->6->7->1->5->4->NULL
 */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        auto p = head;
        auto q = head->next;
        auto even_head = q;
        auto even_tail = q;
        auto odd_tail = p;
        auto temp = head;
        bool p_odd = true;
        while (q != nullptr) {
            p->next = q->next;
            p = p->next;
            temp = p;
            p = q;
            q = temp;
            p_odd = !p_odd;
            if (p_odd) {
                odd_tail = p;
            }
            else {
                even_tail = p;
            }
        }
        odd_tail->next = even_head;
        even_tail = nullptr;
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

ListNode* CreateList(vector<int> data) {
    auto head = new ListNode(0);
    auto p = head;
    for (auto x : data) {
        p->next = new ListNode(x);
        p = p->next;
    }
    p = head->next;
    delete head;
    return p;
}

int main() {
    Solution s;
    auto l1 = CreateList({ 1, 2, 3, 4, 5 });
    ShowList(l1);
    l1 = s.oddEvenList(l1);
    ShowList(l1);
    cout << endl;
    auto l2 = CreateList({ 2, 1, 3, 5, 6, 4, 7 });
    ShowList(l2);
    l2 = s.oddEvenList(l2);
    ShowList(l2);
    cin.get();
    return 0;
}