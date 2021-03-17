#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
238. Product of Array Except Self
"""

from typing import List
from functools import reduce


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        zeros = nums.count(0)
        if zeros >= 2:
            return [0] * len(nums)
        elif zeros == 1:
            idx = nums.index(0)
            all_mul = reduce(lambda acc, x: acc * (x if x != 0 else 1), nums, 1)
            return [0 if i != idx else all_mul for i in range(len(nums))]
        else:
            all_mul = reduce(lambda acc, x: acc * x, nums, 1)
            return [all_mul//num for num in nums]


if __name__ == "__main__":
    solution = Solution()

    nums = [-1, 1, 0, -3, 3]

    print(solution.productExceptSelf(nums))

