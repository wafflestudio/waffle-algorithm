'''
# 121
'''

class Solution:

    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        min_price = sys.maxsize
        
        for today_price in prices:
            if today_price < min_price:
                min_price = today_price
            if today_price - min_price > profit:
                profit = today_price - min_price
                
        return profit



    def maxProfit2(self, prices: List[int]) -> int:
        m, mp = float('inf'), 0

        for p in prices:
            if p < m:
                m = p
            if p - m > mp:
                mp = p - m

        return mp
