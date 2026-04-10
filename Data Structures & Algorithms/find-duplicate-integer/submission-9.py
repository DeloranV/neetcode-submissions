class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            idx = nums[i] if nums[i] > 0 else -1 * nums[i]
            if nums[idx] < 0: return idx
            nums[idx] *= -1