'''
23. Merge k Sorted Lists
108ms, 18MB
'''


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
	def mergeKLists(self, lists: List[ListNode]) -> ListNode:
		pq = []
		head = tail = ListNode()
		for i in range(len(lists)):
			if lists[i]:
				heapq.heappush(pq, (lists[i].val, i))
		while pq:
			(v, i) = heapq.heappop(pq)
			tail.next = ListNode(v)
			tail = tail.next
			lists[i] = lists[i].next
			if lists[i]:
				heapq.heappush(pq, (lists[i].val, i))
		return head.next
