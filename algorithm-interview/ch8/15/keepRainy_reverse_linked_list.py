#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
206. Reverse Linked List
"""

from typing import List


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: ListNode) -> None or ListNode:
        if not head:
            return None
        rev = ListNode(head.val)
        itr = head.next
        while itr:
            tmp = ListNode(itr.val)
            tmp.next = rev
            rev = tmp
            itr = itr.next

        return rev


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
    while itr:
        print(itr.val, end=' ')
        itr = itr.next
    print()


if __name__ == "__main__":
    solution = Solution()

    _head = [1, 2, 3, 4, 5]
    head = make_list(_head)

    print_list(solution.reverseList(head))

