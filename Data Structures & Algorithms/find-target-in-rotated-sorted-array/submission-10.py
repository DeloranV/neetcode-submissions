class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1

        while l <= r:
            middle_idx = l + int((r - l) / 2)
            if nums[middle_idx] == target: return middle_idx
            elif target == nums[l]: return l
            elif target == nums[r]: return r
            if nums[l] < nums[middle_idx]:
                if target > nums[l] and target < nums[middle_idx]: r = middle_idx - 1
                else: l = middle_idx + 1
            else:
                if target > nums[middle_idx] and target < nums[r]: l = middle_idx + 1
                else: r = middle_idx - 1

        return -1