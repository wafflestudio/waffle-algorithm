class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    # Runtime: 64 ms
    # Memory Usage: 14.3MB
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode()
        sum_list = dummy
        round_up = False

        while l1 or l2:
            num_sum = 0
            if l1:
                num_sum += l1.val
                l1 = l1.next
            if l2:
                num_sum += l2.val
                l2 = l2.next

            if round_up:
                num_sum += 1

            round_up = num_sum >= 10
            sum_list.next = ListNode(num_sum % 10)
            sum_list = sum_list.next

        if round_up:
            sum_list.next = ListNode(1)

        return dummy.next