#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
24. Swap Nodes in Pairs
"""

from typing import List


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        itr = head
        dummy = prev = ListNode(-1)
        while itr and itr.next:
            prev.next, itr, itr.next, itr.next.next = itr.next, itr.next, itr, itr.next.next
            prev = itr.next
            itr = itr.next.next
        if itr:
            prev.next = itr

        return dummy.next


def make_list(_head: List) -> None or ListNode:
    if not _head:
        return None
    head = ListNode(_head[0])
    itr = head
    for val in _head[1:]:
        node = ListNode(val)
        itr.next = node
        itr = node
    return head


def print_list(head: ListNode) -> None:
    if not head:
        return
    itr = head
    lst = []
    while itr:
        lst.append(itr.val)
        itr = itr.next
    print('[' + ','.join(map(str, lst)) + ']')


if __name__ == "__main__":
    solution = Solution()

    _head = [1, 2, 3, 4]
    head = make_list(_head)

    print_list(solution.swapPairs(head))

