#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
641. Design Circular Deque
"""

from typing import List
from heapq import heappush, heappop


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        heap = []
        for itr in lists:
            while itr:
                heappush(heap, itr.val)
                itr = itr.next

        head = itr = ListNode(-1)
        while heap:
            itr.next = ListNode(heappop(heap))
            itr = itr.next

        return head.next


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

    _lists = [[], [1]]
    lists = []
    for lst in _lists:
        lists.append(make_list(lst))

    print_list(solution.mergeKLists(lists))

