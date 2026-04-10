class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = [0] * len(nums)
        for i in range(len(nums)):
            if i == 0: 
                prefix[i] = nums[i]
                continue
            prefix[i] = prefix[i - 1] * nums[i]
        
        postfix = [0] * len(nums)
        for i in range(len(nums) - 1, -1, -1):
            if i == (len(nums) - 1): 
                postfix[i] = nums[i]
                continue
            postfix[i] = postfix[i + 1] * nums[i]

        result = [0] * len(nums)
        result[0] = postfix[1]
        result[-1] = prefix[-2]
        for i in range(1, len(nums) - 1):
            result[i] = postfix[i + 1] * prefix[i - 1]
        return result