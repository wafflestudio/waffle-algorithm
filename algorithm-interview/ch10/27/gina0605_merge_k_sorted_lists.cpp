/*
23. Merge k Sorted Lists
24ms, 13.8MB
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

typedef pair<int, int> pii;

#define fi first
#define se second

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		ListNode *head, *tail;
		head = tail = new ListNode();
		for(int i = 0; i < lists.size(); i++) if(lists[i] != nullptr)
			pq.push(pii(lists[i]->val, i));
		while(!pq.empty()) {
			pii t = pq.top();
			pq.pop();
			tail->next = new ListNode(t.fi, nullptr);
			tail = tail->next;
			ListNode* &l = lists[t.se];
			if(l->next != nullptr) {
				l = l->next;
				pq.push(pii(l->val, t.se));
			}
		}
		return head->next;
    }
};
