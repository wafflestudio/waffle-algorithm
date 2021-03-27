class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummy = ListNode()
        swap = dummy

        while head and head.next:
            swap.next = ListNode(head.next.val)
            swap.next.next = ListNode(head.val)

            swap = swap.next.next
            head = head.next.next

        if head:
            swap.next = head

        return dummy.next