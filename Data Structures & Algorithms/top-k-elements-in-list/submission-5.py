class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter_map = {}
        freq_hash_table = [[] for _ in range(len(nums) + 1)]
        res = []

        for num in nums:
            counter_map[num] = counter_map.get(num, 0) + 1
        
        for num, count in counter_map.items():
            freq_hash_table[count].append(num)
        
        for i in range(len(freq_hash_table) - 1, -1, -1):
            res.extend(freq_hash_table[i])

        return res[:k]