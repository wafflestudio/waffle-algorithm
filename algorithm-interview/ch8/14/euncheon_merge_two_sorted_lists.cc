#include <iostream>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode();
        ListNode *curr = head;
        ListNode *c1 = l1, *c2 = l2;
        
        while (c1 != NULL && c2 != NULL) {
            if (c1->val < c2->val) {
                curr->next = new ListNode(c1->val);
                curr = curr->next;
                c1 = c1->next;
            }
            else {
                curr->next = new ListNode(c2->val);
                curr = curr->next;
                c2 = c2->next;
            }
        }
        
        if (c1 != NULL) {
            curr->next = c1;
        }
        else {
            curr->next = c2;
        }
        return head->next;
    }
};