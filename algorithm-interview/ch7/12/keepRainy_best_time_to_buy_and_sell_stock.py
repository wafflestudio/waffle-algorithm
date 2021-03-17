#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
121. Best Time to Buy and Sell Stock
"""

from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        curr_max = prices[-1]
        max_profit = 0
        for price in reversed(prices[:-1]):
            curr_max = max(curr_max, price)
            max_profit = max(max_profit, max(0, curr_max - price))
        return max_profit


if __name__ == "__main__":
    solution = Solution()

    prices = [7, 1, 5, 3, 6, 4]

    print(solution.maxProfit(prices))

