"""
24. Swap Nodes in Pairs
32ms, 14.3MB
"""
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
	def swapPairs(self, head: ListNode) -> ListNode:
		p = ListNode(next=head)
		if head is not None and head.next is not None:
			head = head.next
		while p.next is not None and p.next.next is not None:
			q = p.next
			r = q.next
			s = r.next
			p.next = r
			r.next = q
			q.next = s
			p = q
		return head
