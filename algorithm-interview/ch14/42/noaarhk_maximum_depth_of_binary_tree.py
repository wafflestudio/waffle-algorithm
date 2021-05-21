# Definition for a binary tree node.
import collections
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __str__(self):
        ret = str(self.val) + "\n"
        if self.left:
            ret += str(self.left)
        if self.right:
            ret += str(self.right)
        return ret


class Solution:

    def maxDepth(self, root: TreeNode) -> int:

        if root is None:
            return 0

        queue = collections.deque([root]) # BFS

        depth = 0

        while queue:
            depth += 1

            for _ in range(len(queue)):
                cur_root = queue.popleft()

                if cur_root.left:
                    queue.append(cur_root.left)
                if cur_root.right:
                    queue.append(cur_root.right)

        return depth


def _to_tree(l: List, idx: int): # 리스트를 트리구조로 변환
    if idx >= len(l):
        return None
    _root = TreeNode(val=l[idx])
    _root.left = _to_tree(l, idx * 2 + 1) # null head 가 없기 때문에 인덱스 1추가
    _root.right = _to_tree(l, idx * 2 + 2)
    return _root


if __name__ == '__main__':

    root = [3, 9, 20, None, None, 15, 7]

    # answer: 3
    treenode = _to_tree(root, 0)

    solution = Solution()

    print(solution.maxDepth(treenode))