class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy = 10000
        res = 0
        for price in prices:
            res = max(res, price-buy)
            buy = min(buy, price)
        
        return res