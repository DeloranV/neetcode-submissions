class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram_groups = defaultdict(list)

        for s in strs:
            char_counter = [0] * 26
            for c in s:
                char_counter[ord(c) - ord('a')] += 1
            anagram_groups[tuple(char_counter)].append(s)
    
        return list(anagram_groups.values())