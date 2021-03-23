/*
328. Odd Even Linked List
12ms, 10.4MB
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oh, *ot, *eh, *et;
		oh = ot = new ListNode();
		eh = et = new ListNode();
		while(head != nullptr) {
			ot->next = head;
			ot = ot->next;
			head = head->next;
			if(head != nullptr) {
				et->next = head;
				et = et->next;
				head = head->next;
			}
		}
		ot->next = eh->next;
		et->next = nullptr;
		return oh->next;
    }
};
