# Definition for a binary tree node.


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        pass


def _to_tree(l, i):
    if i >= len(l):
        return None
    root = TreeNode(val=l[i])
    root.left = _to_tree(l, i * 2 + 1)
    root.right = _to_tree(l, i * 2 + 2)
    return root


if __name__ == '__main__':
    num_list = list(range(1, 6))
    root = _to_tree(num_list, 0)
    solution = Solution()
