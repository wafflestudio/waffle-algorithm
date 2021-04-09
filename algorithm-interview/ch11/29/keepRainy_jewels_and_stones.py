#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
771. Jewels and Stones
"""

from collections import Counter
from functools import reduce


class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        counter = Counter(stones)
        return reduce(lambda x, y: x+counter[y], jewels, 0)


if __name__ == "__main__":
    solution = Solution()

    jewels = "aA"
    stones = "aAAbbbb"

    print(solution.numJewelsInStones(jewels, stones))

