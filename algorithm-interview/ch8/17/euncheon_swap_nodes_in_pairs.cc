#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy_head = new ListNode(0, head);
        ListNode *curr = dummy_head;
        
        while (curr->next != nullptr && curr->next->next != nullptr) {
            ListNode *a = curr->next;
            ListNode *b = curr->next->next;
            curr->next = b;
            a->next = b->next;
            b->next = a;
            curr = a;
        }
        
        return dummy_head->next;
    }
};