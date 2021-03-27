class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Solution:
    def isPalindrome(self, head: Node) -> bool:
        node = head
        comp = []
        while node:
            comp.append(node.data)
            node = node.next

        node = head
        for val in comp[::-1]:
            if val != node.data:
                return False
            node = node.next
        return True


if __name__ == '__main__':
    solution = Solution()
    nums = [1, 2]
    head = Node(nums[0])
    itr = head
    for val in nums:
        node = Node(val)
        itr.next = node
        itr = node

    print(solution.isPalindrome(head))
