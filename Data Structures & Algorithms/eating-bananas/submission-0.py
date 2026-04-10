class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        min_eating_rate, max_eating_rate = None, max(piles)
        l, r = 1, max_eating_rate

        while l <= r:
            middle_eating_rate = l + int((r - l) / 2)
            time_needed = 0
            for pile in piles:
                time_needed += math.ceil(pile / middle_eating_rate)
            if time_needed <= h: 
                min_eating_rate = min(min_eating_rate, middle_eating_rate) if min_eating_rate else middle_eating_rate
                r = middle_eating_rate - 1
            else: l = middle_eating_rate + 1

        return min_eating_rate