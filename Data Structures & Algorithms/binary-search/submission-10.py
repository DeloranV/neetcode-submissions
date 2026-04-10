class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1

        while l <= r:
            middle_idx = l + int((r - l) / 2)
            if nums[middle_idx] == target: return middle_idx
            elif nums[middle_idx] < target: l = middle_idx + 1
            else: r = middle_idx - 1
        
        return middle_idx if nums[middle_idx] == target else -1