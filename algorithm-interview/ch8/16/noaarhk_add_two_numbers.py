from typing import List


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# class Solution0:
#
#     # 연결리스트 뒤집기
#     def reverseList(self, head: ListNode) -> ListNode:
#         curr = head
#         prev = None
#         while curr:
#             temp = curr.next
#             curr.next = prev
#             prev = curr
#             curr = temp
#         return prev
#
#     # 연결리스트를 파이썬리스트로
#     def toList(self, curr: ListNode) -> List:
#         list_py: List = []
#         while curr:
#             list.append(curr.val)
#             curr = curr.next
#         return list_py
#
#     def toReversedLinkedList(self, result: List) -> ListNode:
#         prev = None
#         for r in result:
#             node = ListNode(r)
#             node.next = prev
#             prev = node
#         return node
#
#     def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
#         a = self.toList(self.reverseList(l1))
#         b = self.toList(self.reverseList(l2))
#
#         resultStr = int(''.join(str(e) for e in a)) + int(''.join(str(e) for e in b))
#
#         return self.toReversedLinkedList(str(resultStr).split())


class Solution:
    def addTwoNumber(self, l1: ListNode, l2: ListNode) -> ListNode:
        # 정답 연결구조
        root = head = ListNode(0)

        # 10으로 나눈 몫
        carry = 0

        # 연결리스트가 존재하는 구간에서 반복, 올림자리가 있을 때 반복
        while l1 or l2 or carry:
            # 자리수 별로 구한 합계 초기화
            sum = 0
            if l1:
                sum += l1.val
                l1 = l1.next
            if l2:
                sum += l2.val
                l2 = l2.next

            carry, val = divmod(sum + carry, 10)
            head.next = ListNode(val)
            head = head.next
        return root.next


def to_listnode(l: List):
    head = ListNode(l[0])
    itr = head
    for val in l[1:]:
        node = ListNode(val)
        itr.next = node
        itr = node
    return head


def print_list(l: ListNode):
    itr = l
    while itr:
        print(itr.val, end=' ', )
        itr = itr.next



if __name__ == '__main__':
    solution = Solution()
    l_1 = [2, 4]
    l_2 = [5, 6, 4]
    l1 = to_listnode(l_1)
    l2 = to_listnode(l_2)
    print_list(solution.addTwoNumber(l1, l2))
