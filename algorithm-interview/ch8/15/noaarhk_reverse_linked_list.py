from typing import List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverse(self, head: ListNode) -> ListNode:
        curr = head
        prev = None
        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        return prev


def to_list(l: List):
    head = ListNode(l[0])
    itr = head
    for val in l:
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


if __name__ == '__main__':
    a = [1, 2, 3, 4, 5]
    b = to_list(a)
    solution = Solution()

    print_list(solution.reverse(b))
