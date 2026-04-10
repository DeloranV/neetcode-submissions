class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)
        res = max(piles)

        while l <= r:
            midEatingSpeed = l + int((r - l) / 2)
            time_eating = 0
            for pile in piles: time_eating += math.ceil(pile / midEatingSpeed)
            if time_eating > h: l = midEatingSpeed + 1
            else: 
                res = min(res, midEatingSpeed)
                r = midEatingSpeed - 1

        return res