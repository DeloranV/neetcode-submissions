class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix = [0] * n
        for i in range(n):
            if i == 0: 
                prefix[i] = nums[i]
                continue
            prefix[i] = prefix[i - 1] * nums[i]
        
        postfix = [0] * n
        for i in range(n - 1, -1, -1):
            if i == (n - 1): 
                postfix[i] = nums[i]
                continue
            postfix[i] = postfix[i + 1] * nums[i]

        result = [0] * n
        result[0] = postfix[1]
        result[-1] = prefix[-2]
        for i in range(1, n - 1):
            result[i] = postfix[i + 1] * prefix[i - 1]
        return result