class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    # 660 ms 31.5 MB
    def isPalindrome(self, head: ListNode) -> bool:
        fast = head
        slow = head
        rev = None

        while fast and fast.next:
            fast = fast.next.next
            rev, rev.next, slow = slow, rev, slow.next
        if fast:
            slow = slow.next

        while rev:
            if rev.val != slow.val:
                return False
            else:
                rev = rev.next
                slow = slow.next
        return True

    # 808 ms 46.9 MB
    def isPalindrome2(self, head: ListNode) -> bool:
        lst = []
        cur = head
        while cur != None:
            lst.append(cur.val)
            cur = cur.next

        return lst == list(reversed(lst))
