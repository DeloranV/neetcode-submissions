class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        unique = set()
        for elem in nums:
            unique.add(elem)
        if len(nums) != len(unique): return True
        return False