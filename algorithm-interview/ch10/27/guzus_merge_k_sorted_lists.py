# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        pq = []
        res = ListNode()
        head = res
        for i in range(len(lists)):
            if lists[i]:                
                heapq.heappush(pq, (lists[i].val, i))
        while len(pq)>0 :
            node = heapq.heappop(pq)
            val = node[0]
            idx = node[1]
            res.next = ListNode(val=val, next=None)
            res = res.next
            if lists[idx].next:
                lists[idx] = lists[idx].next
                heapq.heappush(pq, (lists[idx].val, idx))
        return head.next