class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            curr_elem = nums[i] if nums[i] > 0 else 0 - nums[i]
            if nums[curr_elem - 1] < 0: return curr_elem
            nums[curr_elem - 1] = 0 - nums[curr_elem - 1]