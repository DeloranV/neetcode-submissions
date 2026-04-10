class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        res = nums[0]

        while l <= r:
            middle_idx = l + int((r - l) / 2)
            res = min(res, nums[middle_idx])
            if nums[l] < nums[r]: res = min(res, nums[l])
            if nums[l] <= nums[middle_idx]: l = middle_idx + 1
            else: r = middle_idx - 1
        
        return res