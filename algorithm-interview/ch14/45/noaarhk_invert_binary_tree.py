# Definition for a binary tree node.
import collections


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        que = collections.deque([root])

        while que:
            node = que.popleft()
            if node:
                node.left, node.right = node.right, node.left

                que.append(node.left)
                que.append(node.right)
        return root


def _to_tree(l, i):
    if i >= len(l):
        return None
    root = TreeNode(val=l[i])
    root.left = _to_tree(l, i * 2 + 1)
    root.right = _to_tree(l, i * 2 + 2)
    return root


if __name__ == '__main__':
    list = [4, 2, 7, 1, 3, 6, 9]
    root = _to_tree(list, 0)
    solution = Solution()
    solution.invertTree(root)
