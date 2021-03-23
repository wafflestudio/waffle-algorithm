#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
21. Merge Two Sorted Lists
"""

from typing import List
import sys


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        ret = itr = ListNode(-sys.maxsize)
        while l1 and l2:
            v1 = l1.val
            v2 = l2.val
            if v1 <= v2:
                itr.next = ListNode(v1)
                l1 = l1.next
            else:
                itr.next = ListNode(v2)
                l2 = l2.next
            itr = itr.next

        if l1:
            itr.next = l1
        if l2:
            itr.next = l2

        return ret.next


def make_list(_l: List):
    head = ListNode(_l[0])
    itr = head
    for val in _l[1:]:
        node = ListNode(val)
        itr.next = node
        itr = node
    return head


def print_list(l: ListNode):
    itr = l
    while itr:
        print(itr.val, end=' ')
        itr = itr.next
    print()


if __name__ == "__main__":
    solution = Solution()

    _l1 = [1, 2, 4]
    l1 = make_list(_l1)
    _l2 = [1, 3, 4]
    l2 = make_list(_l2)

    print_list(solution.mergeTwoLists(l1, l2))

