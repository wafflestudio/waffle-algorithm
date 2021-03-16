#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
42. Trapping Rain Water
"""

from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)

        left_max_height = [-1] * n
        right_max_height = [-1] * n
        for i in range(1, n):
            left_max_height[i] = max(left_max_height[i-1], height[i-1])
        for i in range(n-2, 0-1, -1):
            right_max_height[i] = max(right_max_height[i+1], height[i+1])

        ret = 0
        for i in range(1, n-1):
            trapped = max(0, min(left_max_height[i], right_max_height[i])-height[i])
            ret += trapped

        return ret


if __name__ == "__main__":
    solution = Solution()

    height = [4,2,0,3,2,5]

    print(solution.trap(height))

