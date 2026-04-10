class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        minimum = nums[0]

        while l <= r:
            if nums[l] < nums[r]: 
                minimum = min(minimum, nums[l])
                break
            middle_idx = l + int((r - l) / 2)
            minimum = min(minimum, nums[middle_idx])
            if nums[l] <= nums[middle_idx]: l = middle_idx + 1
            else: r = middle_idx - 1

        return minimum