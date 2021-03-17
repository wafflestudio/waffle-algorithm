#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
561. Array Partition I
"""

from typing import List


class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        return sum([min(nums[i:i+2]) for i in range(0, len(nums), 2)])


if __name__ == "__main__":
    solution = Solution()

    nums = [6,2,6,5,1,2]

    print(solution.arrayPairSum(nums))

