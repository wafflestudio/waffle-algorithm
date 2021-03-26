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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t1 = l1, *t2 = l2;
        int carry = 0, temp = 0;
        ListNode *dummy_head = new ListNode(0);
        ListNode *curr_node = dummy_head;
        while (t1 != nullptr && t2 != nullptr) {
            temp = t1->val + t2->val + carry;
            carry = temp / 10;
            temp %= 10;
            curr_node->next = new ListNode(temp);
            curr_node = curr_node->next;
            t1 = t1->next;
            t2 = t2->next;
        }
        
        if (t1 == nullptr && t2 == nullptr) {
            if (carry != 0) {
                curr_node->next = new ListNode(carry);
            }
        }
        else{
            if (t1 != nullptr) {
                curr_node->next = t1;
            }
            else if (t2 != nullptr) {
                curr_node->next = t2;
            }
            
            while(curr_node->next != nullptr && carry != 0) {
                temp = curr_node->next->val += carry;
                carry = temp / 10;
                temp %= 10;
                curr_node->next->val = temp;
                curr_node = curr_node->next;
            }
            
            if (carry != 0) {
                curr_node->next = new ListNode(carry);
            }
        }

        
        return dummy_head->next;
    }
};