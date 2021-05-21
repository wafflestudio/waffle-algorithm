#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
104. Maximum Depth of Binary Tree
"""

from typing import List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0

        dep = 0
        que = [root]

        while que:
            sz = len(que)
            dep += 1
            while sz:
                sz -= 1
                curr = que.pop(0)
                if curr.left is not None:
                    que.append(curr.left)
                if curr.right is not None:
                    que.append(curr.right)

        return dep


def make_root(lst: List[int or None]) -> TreeNode or None:
    if not lst:
        return None

    root = TreeNode(lst[0])

    def make_node(parent: TreeNode, idx: int):
        left_idx = 2 * idx + 1
        if left_idx < len(lst) and lst[left_idx] is not None:
            left_child = TreeNode(lst[left_idx])
            parent.left = make_node(left_child, left_idx)

        right_idx = 2 * idx + 2
        if right_idx < len(lst) and lst[right_idx] is not None:
            right_child = TreeNode(lst[right_idx])
            parent.right = make_node(right_child, right_idx)

        return parent

    root = make_node(root, 0)
    return root


if __name__ == "__main__":
    solution = Solution()

    root = make_root([3, 9, 20, None, None, 15, 7])

    print(solution.maxDepth(root))

