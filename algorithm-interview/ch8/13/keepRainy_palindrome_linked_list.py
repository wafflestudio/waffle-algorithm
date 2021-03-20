#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
234. Palindrome Linked List
"""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        slow = fast = head
        rev = ListNode(slow.val)
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            rev = ListNode(slow.val, rev)
        if not fast:
            rev = rev.next

        while rev and rev.val == slow.val:
            rev, slow = rev.next, slow.next

        return rev is None


if __name__ == "__main__":
    solution = Solution()

    _head = [1, 2]
    head = ListNode(_head[0])
    itr = head
    for val in _head[1:]:
        node = ListNode(val)
        itr.next = node
        itr = node

    print(solution.isPalindrome(head))

