class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0] * n
        prefix = 1
        postfix = 1

        for i in range(n):
            res[i] = prefix
            prefix *= nums[i]

        for i in range(n - 1, -1, -1):
            res[i] = postfix * res[i]
            postfix *= nums[i]

        return res