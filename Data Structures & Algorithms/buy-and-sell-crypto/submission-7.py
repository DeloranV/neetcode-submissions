class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2: return 0
        max_profit = 0
        l, r = 0, 1

        while r < len(prices):
            if prices[r] < prices[l] and r < len(prices) - 1:
                l, r = r, r + 1
                continue
            max_profit = max(max_profit, prices[r] - prices[l])
            r += 1

        return max_profit