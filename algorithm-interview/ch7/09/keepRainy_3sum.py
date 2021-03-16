#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
15. 3Sum
"""

from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ret = set()
        for i in range(len(nums)-2):
            l, r = i+1, len(nums)-1
            print(nums[i], nums[l], nums[r])
            while l < r:
                tmp = (nums[i], nums[l], nums[r])
                if 0 == sum(tmp):
                    if tmp not in ret:
                        ret.add(tmp)
                    l += 1
                    r -= 1
                elif 0 > sum(tmp):
                    l += 1
                elif 0 < sum(tmp):
                    r -= 1
        return list(map(list, ret))


if __name__ == "__main__":
    solution = Solution()

    nums = [-1,0,1,2,-1,-4]

    print(solution.threeSum(nums))

