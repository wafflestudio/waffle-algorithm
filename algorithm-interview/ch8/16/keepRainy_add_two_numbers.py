#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
2. Add Two Numbers
"""

from typing import List


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        ret = itr = ListNode(-1)
        while l1 or l2:
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0
            itr.next = ListNode((v1+v2+carry) % 10)
            itr = itr.next
            carry = (v1+v2+carry) // 10
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        if carry:
            itr.next = ListNode(1)

        return ret.next


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

    _l1 = [9, 9, 9, 9, 9, 9, 9]
    l1 = make_list(_l1)
    _l2 = [9, 9, 9, 9]
    l2 = make_list(_l2)

    print_list(solution.addTwoNumbers(l1, l2))

