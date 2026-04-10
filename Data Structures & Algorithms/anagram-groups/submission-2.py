class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hash_map = defaultdict(list)
        for s in strs:
            hash_table = [0] * 26
            for c in s:
                hash_table[ord(c) % 97] += 1
            hash_map[tuple(hash_table)].append(s)
        return list(hash_map.values())