"""
Reverse Linked List
author: davin111
"""
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        avg runtime (5 attempts): 33.6ms
        runtime beats: about 87%
        memory usage beats: 26%
        """
        if not head:
            return None

        this_head = head
        reversed_list = ListNode(this_head.val)
        while this_head.next is not None:  # O(n)
            this_head = this_head.next
            reversed_list = ListNode(this_head.val, reversed_list)

        return reversed_list

    def reverse_list_recursive(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        avg runtime: 36ms
        """
        def reverse_list(node, prev=None):
            if not node:
                return prev
            next, node.next = node.next, prev
            return reverse_list(next, node)

        return reverse_list(head)


if __name__ == "__main__":
    import json

    try:
        vals = json.loads(input())
    except json.JSONDecodeError:
        exit(1)

    if not isinstance(vals, list):
        exit(1)

    def list_to_link(lst):
        if len(lst) == 1:
            return ListNode(lst[0])
        return ListNode(lst[0], list_to_link(lst[1:]))

    reversed_list = Solution().reverseList(list_to_link(vals))
    if not reversed_list:
        exit(0)

    print(f"[{reversed_list.val}", end="")
    this_head = reversed_list
    while this_head.next is not None:
        this_head = this_head.next
        print(f", {this_head.val}", end="")
    print("]")
