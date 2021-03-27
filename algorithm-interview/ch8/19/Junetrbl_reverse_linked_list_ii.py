class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        dummy = ListNode()
        rev = dummy
        rev.next = head

        for i in range(left - 1):
            rev = rev.next
        head = rev.next

        for i in range(right - left):
            tmp, rev.next, head.next = rev.next, head.next, head.next.next
            rev.next.next = tmp

        return dummy.next