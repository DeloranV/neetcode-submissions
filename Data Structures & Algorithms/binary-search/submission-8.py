class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def binary_search(l, r):
            if l == r and nums[l] == target: return l
            if l > r or (l == r and nums[l] != target): return -1
            
            middle_idx = l + int((r - l) / 2)
            if nums[middle_idx] < target: return binary_search(middle_idx + 1, r)
            elif nums[middle_idx] > target: return binary_search(l, middle_idx - 1)
            else: return middle_idx
        
        return binary_search(0, len(nums) - 1)