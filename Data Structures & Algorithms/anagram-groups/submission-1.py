class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hash_map = defaultdict(list)
        for s in strs:
            s_sorted = "".join(sorted(s))
            hash_map[s_sorted].append(s)
        return list(hash_map.values())