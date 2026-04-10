class Solution:
    def search(self, nums: List[int], target: int) -> int:
        
        def binary_search(l, r):
            if l < 0 or r < 0: return -1
            middle_idx = l + int((r - l) / 2)
            if nums[middle_idx] == target: return middle_idx
            elif l == r: return -1
            elif nums[middle_idx] > target: return binary_search(l, middle_idx - 1)
            else: return binary_search(middle_idx + 1, r)

        return binary_search(0, len(nums) - 1)