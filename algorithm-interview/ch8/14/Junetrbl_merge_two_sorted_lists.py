class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    # Runtime: 40 ms
    # Memory Usage: 14.1MB
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode()
        sorted_list = dummy

        while l1 and l2:
            if l1.val <= l2.val:
                sorted_list.next = l1
                sorted_list = sorted_list.next
                l1 = l1.next
                if not l1:
                    break
            else:
                sorted_list.next = l2
                sorted_list = sorted_list.next
                l2 = l2.next
                if not l1:
                    break

        if not l1:
            sorted_list.next = l2

        if not l2:
            sorted_list.next = l1

        return dummy.next

    # Runtime: 36 ms
    # Memory Usage: 14.4 MB
    def recursiveMergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        if not l2:
            return l1

        if l1.val <= l2.val:
            sorted_list = l1
            sorted_list.next = self.mergeTwoLists(l1.next, l2)
        else:
            sorted_list = l2
            sorted_list.next = self.mergeTwoLists(l1, l2.next)

        return sorted_list