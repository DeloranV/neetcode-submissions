class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1

        while l < r:
            middle_idx = l + int((r - l) / 2)
            if nums[middle_idx] == target: return middle_idx
            elif nums[l] == target: return l
            elif nums[r] == target: return r
            if nums[l] <= nums[middle_idx]:
                if target < nums[middle_idx] and target > nums[l]: r = middle_idx - 1
                elif target > nums[middle_idx] and target > nums[r]: l = middle_idx + 1
                elif target > nums[middle_idx] or target < nums[l]: l = middle_idx + 1
                else: return -1
            elif nums[middle_idx] < nums[r]:
                if target > nums[middle_idx] and target < nums[r]: l = middle_idx + 1
                elif target > nums[middle_idx] and target > nums[r]: r = middle_idx - 1
                elif target > nums[r] or target < nums[middle_idx]: r = middle_idx - 1
                else: return -1

        return l if nums[l] == target else -1