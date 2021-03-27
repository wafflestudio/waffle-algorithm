class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    # 32 ms 15.5 MB
    def reverseList(self, head: ListNode) -> ListNode:
        rev = None
        while head:
            rev, rev.next, head = head, rev, head.next

        return rev
