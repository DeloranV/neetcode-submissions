class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0: return 0
        res = []
        nums = sorted(nums)
        for i in range(len(nums)):
            unique = set()
            unique.add(nums[i])
            seq = [nums[i]]
            for j in range(i, len(nums)):
                if i == j: continue
                if nums[j] in unique: continue
                unique.add(nums[j])
                if nums[j] != seq[-1] + 1: break
                seq.append(nums[j])
            res.append(len(seq))
        return max(res)
