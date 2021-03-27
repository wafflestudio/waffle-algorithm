class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    # 36 ms 16.4 MB
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head:
            return None

        odd_dummy = ListNode()
        even_dummy = ListNode()

        odd = odd_dummy
        even = even_dummy

        odd.next = head
        even.next = head.next

        odd = odd.next
        even = even.next

        while odd.next and even.next:
            odd.next, even.next = odd.next.next, even.next.next
            odd = odd.next
            even = even.next

        odd.next = even_dummy.next
        return odd_dummy.next