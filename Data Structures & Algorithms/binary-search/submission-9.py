class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1

        while l <= r:
            middle_offset = l + int((r - l / 2))
            if nums[middle_offset] < target: l = middle_offset + 1
            elif nums[middle_offset] > target: r = middle_offset - 1
            else: return middle_offset
        
        return -1