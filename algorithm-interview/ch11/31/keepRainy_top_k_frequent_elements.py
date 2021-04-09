#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
347. Top K Frequent Elements
"""

from typing import List
from collections import Counter


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        return [num for num, cnt in Counter(nums).most_common(k)]


if __name__ == "__main__":
    solution = Solution()

    nums = [1, 1, 1, 2, 2, 3]
    k = 2

    print(solution.topKFrequent(nums, k))

