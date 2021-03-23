/*
234. Palindrome Linked List
160ms, 110.2MB
*/

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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int N = 1;
		ListNode *tail;
		for(tail = head; tail->next != nullptr; tail = tail->next) N++;

		ListNode *r = nullptr;
		for(int i = 0; i < N / 2; i++) {
			ListNode *t = head;
			head = head->next;
			t->next = r;
			r = t;
		}
		if(N % 2 == 1) head = head->next;
		for(int i = 0; i < N / 2; i++) {
			if(r->val != head->val) return false;
			r = r->next;
			head = head->next;
		}
		return true;
    }
};
