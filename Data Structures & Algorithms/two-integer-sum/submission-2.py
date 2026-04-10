class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_map = {}

        for i in range(len(nums)):
            hash_map[nums[i]] = i

        for i in range(len(nums)):
            diff = target - nums[i]
            idx = hash_map.get(diff, None)
            if idx == i: continue
            if idx != None: return [i, idx]