class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        res = []
        for target in range(len(nums)):
            if target > 0 and nums[target - 1] == nums[target]: continue
            l, r = target + 1, len(nums) - 1

            while (l < r) and (l < len(nums)) and (r <= len(nums)):
                if l - 1 != target and nums[l - 1] == nums[l]: 
                    l += 1
                    continue
                if (nums[l] + nums[r]) == -(nums[target]): 
                    res.append([nums[l], nums[target], nums[r]])
                    l , r = l + 1, r - 1
                elif (nums[l] + nums[r]) < -(nums[target]):
                    l += 1
                else:
                    r -= 1
        return res
