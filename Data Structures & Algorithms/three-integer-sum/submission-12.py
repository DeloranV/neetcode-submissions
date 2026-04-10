class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []

        for target in range(len(nums)):
            if target > 0 and nums[target - 1] == nums[target]: continue
            l ,r = target + 1, len(nums) - 1
            
            while l < r:
                if target != (l - 1) and nums[l] == nums[l - 1]:
                    l += 1
                    continue
                if nums[l] + nums[r] < -(nums[target]):
                    l += 1
                    continue
                elif nums[l] + nums[r] > -(nums[target]):
                    r -= 1
                    continue
                else:
                    res.append([nums[l], nums[target], nums[r]])
                    l += 1
                    r -= 1
        return res