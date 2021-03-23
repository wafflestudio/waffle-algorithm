/*
92. Reverse Linked List II
4ms, 7.5MB
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        head = new ListNode(0, head);
		ListNode *l = head;
		for(int i = 0; i < left - 1; i++) l = l->next;
		ListNode *rh, *rt;
		rh = rt = l->next;
		ListNode *p = rh->next;
		for(int i = 0; i < right - left; i++) {
			ListNode *q = p->next;
			p->next = rh;
			rh = p;
			p = q;
		}
		l->next = rh;
		rt->next = p;
		return head->next;
    }
};
