class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        if nums[l] < nums[r]: return nums[l]
        minimum = 1001

        while l <= r:
            middle_idx = l + int((r - l) / 2)
            minimum = min(minimum, nums[middle_idx])
            if nums[l] < nums[middle_idx]:
                l = middle_idx
            elif nums[middle_idx] < nums[r]:
                r = middle_idx
            else: 
                l += 1

        return minimum