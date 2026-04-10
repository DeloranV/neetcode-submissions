class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hash_map = defaultdict(list)
        for i in range(len(strs)):
            s_sorted = "".join(sorted(strs[i]))
            hash_map[s_sorted].append(strs[i])
        return list(hash_map.values())