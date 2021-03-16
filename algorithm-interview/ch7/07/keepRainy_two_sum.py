#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
1. Two Sum
"""

from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums = list(zip(range(len(nums)), nums))
        nums.sort(key=lambda x: (x[1], x[0]))
        l, r = 0, len(nums)-1
        while l < r:
            if target == nums[l][1] + nums[r][1]:
                return [nums[l][0], nums[r][0]]
            elif target > nums[l][1] + nums[r][1]:
                l += 1
            elif target < nums[l][1] + nums[r][1]:
                r -= 1


if __name__ == "__main__":
    solution = Solution()

    nums = [3, 2, 4]
    target = 6

    print(solution.twoSum(nums, target))

