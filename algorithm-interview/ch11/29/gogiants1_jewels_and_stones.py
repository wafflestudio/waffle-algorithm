"""
771. Jewels and Stones
"""

class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        count_j= collections.Counter(stones)
        n = 0
        for j in jewels:
            n += count_j[j]
        return n 

    def numJewelsInStones_2(self, jewels: str, stones: str) -> int:
        return sum(s in jewels for s in stones)