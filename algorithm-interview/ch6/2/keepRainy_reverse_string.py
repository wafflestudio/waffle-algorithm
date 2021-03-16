#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
344. Reverse String
"""

from typing import List


class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        s.reverse()


if __name__ == "__main__":
    solution = Solution()

    s = ["h","e","l","l","o"]

    solution.reverseString(s)
    print(s)

