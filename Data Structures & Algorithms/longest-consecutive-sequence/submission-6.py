class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0: return 0
        nums_s = sorted(nums)
        res = []
        count = 1
        for i in range(1, len(nums_s)):
            if nums_s[i] == nums_s[i - 1]: continue
            elif nums_s[i] == nums_s[i - 1] + 1: count += 1 
            else:
                res.append(count)
                count = 1
        res.append(count)
        return max(res)