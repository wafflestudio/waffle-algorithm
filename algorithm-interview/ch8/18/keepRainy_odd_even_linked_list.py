#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
328. Odd Even Linked List
"""

from typing import List


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        odd_dummy = odd_itr = ListNode(-1)
        even_dummy = even_itr = ListNode(-1)
        while head:
            if head:
                odd_itr.next = head
                odd_itr, head = odd_itr.next, head.next
                if not head:
                    even_itr.next = None
            if head:
                even_itr.next = head
                even_itr, head = even_itr.next, head.next
                if not head:
                    odd_itr.next = None

        odd_head = odd_dummy.next
        odd_itr.next = even_dummy.next

        return odd_head


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

    _head = [2, 1, 3, 5, 6, 4, 7]
    head = make_list(_head)

    print_list(solution.oddEvenList(head))

