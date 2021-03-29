/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
4ms, 7.4MB
time complexity: O(n)
space complexity: O(1)
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *curr = head;
        ListNode *left_node = nullptr, *right_node = nullptr;
        ListNode *prev = nullptr;
        ListNode *temp = nullptr;
        
        for (int i=0; i<left-1; i++) {
            prev = curr;
            curr = curr->next;
        }
        left_node = prev;
        right_node = curr;
        
        for (int i=left; i<right+1; i++) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        if (left_node == nullptr) {
            head = prev;
        }
        else {
            left_node->next = prev;
        }
        
        right_node->next = curr;
        return head;
    }
};