class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        diff_map = {}

        for i in range(len(numbers)):
            if numbers[i] in diff_map: return [diff_map[numbers[i]] + 1, i + 1]
            diff = target - numbers[i]
            diff_map[diff] = i