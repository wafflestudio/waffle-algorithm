from typing import List


class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if (not l1) or (l2 and l1.val > l2.val):
            l1, l2 = l2, l1
        if l1:
            l1.next = self.mergeTwoLists(l1.next, l2)
        return l1


def to_list(l: List):
    head = ListNode(l[0])
    itr = head
    for val in l:
        node = ListNode(val)
        itr.next = node
        itr = node
    return head


def print_list(l: ListNode):
    itr = l
    while itr:
        print(itr.val, end=' ',)
        itr = itr.next
    print()


if __name__ == '__main__':
    solution = Solution()
    l1_list = [1, 2, 4]
    l2_list = [1, 3, 4]
    l1 = to_list(l1_list)
    l2 = to_list(l2_list)

    print_list(solution.mergeTwoLists(l1, l2))
