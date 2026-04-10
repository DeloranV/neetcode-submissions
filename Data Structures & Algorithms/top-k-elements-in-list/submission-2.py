class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hash_map = {}
        for num in nums:
            hash_map[num] = hash_map.get(num, 0) + 1

        count_map = [[] for _ in range(len(nums) + 1)]
        for num, freq in hash_map.items():
            count_map[freq].append(num)
        
        results = []
        for i in range(len(count_map) - 1, 0, -1):
            if len(count_map[i]) != 0:
                results.extend(count_map[i])

        return results[:k]