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
Solution 1. 
12ms, 10.4MB
time complexity: O(n)
space complexity: O(1)
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd_head = new ListNode();
        ListNode *odd_tail = odd_head;
        ListNode *even_head = new ListNode();
        ListNode *even_tail = even_head;
        
        ListNode *curr = head;
        int idx = 1;
        
        while (curr != nullptr) {
            if (idx % 2 == 1) {
                odd_tail->next = curr;
                odd_tail = odd_tail->next;
            }
            else {
                even_tail->next = curr;
                even_tail = even_tail->next;
            }
            curr = curr->next;
            ++idx;
        }
        odd_tail->next = even_head->next;
        even_tail->next = nullptr;
        
        return odd_head->next;
    }
};

/*
Solution 2. 
8ms, 10.3MB
time complexity: O(n)
space complexity: O(1)
*/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return nullptr;
        
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *even_head = even;
        
        while(even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        
        return head;
    }
};