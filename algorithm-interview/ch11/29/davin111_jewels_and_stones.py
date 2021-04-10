"""
Jewels and Stones
author: davin111
"""
class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        """
        avg runtime (5 attempts): 27.2ms
        runtime beats: about 82%
        memory usage beats: 13%
        """
        # O(j + s)
        jewel_dict = {}
        for j in jewels:  # O(j)
            jewel_dict[j] = 1

        jewel_count = 0
        for s in stones:  # O(s)
            if s in jewel_dict:
                jewel_count += 1

        return jewel_count

    def num_jewels_in_stones(self, jewels: str, stones: str) -> int:
        """
        avg runtime: 29.6ms
        """
        return sum(s in jewels for s in stones)


if __name__ == "__main__":
    jewels = input("J = ")
    stones = input("S = ")

    jewel_count = Solution().numJewelsInStones(jewels, stones)
    print(jewel_count)
