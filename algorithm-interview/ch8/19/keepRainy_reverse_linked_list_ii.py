#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
92. Reverse Linked List II
"""

from typing import List


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        dummy = first = last = ListNode(-1)
        idx = 0
        itr = head
        while itr:
            idx += 1

            if left <= idx <= right:
                if first == last:
                    first.next = ListNode(itr.val)
                    last = first.next
                else:
                    tmp = ListNode(itr.val)
                    tmp.next = first.next
                    first.next = tmp
            elif idx < left:
                first.next = ListNode(itr.val)
                first = first.next
                last = first
            elif idx > right:
                last.next = ListNode(itr.val)
                last = last.next

            itr = itr.next

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

    _head = [1, 2, 3, 4, 5]
    head = make_list(_head)
    left, right = 4, 5

    print_list(solution.reverseBetween(head, left, right))

