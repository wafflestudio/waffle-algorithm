/*
24. Swap Nodes in Pairs
4ms, 7.6MB
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
    ListNode* swapPairs(ListNode* head) {
		ListNode *p = new ListNode(0, head);
		if(head != nullptr && head->next != nullptr) head = head->next;
		while(p->next != nullptr && p->next->next != nullptr) {
			ListNode *q = p->next;
			ListNode *r = q->next;
			ListNode *s = r->next;
			p->next = r;
			r->next = q;
			q->next = s;
			p = q;
		}
		return head;
    }
};
