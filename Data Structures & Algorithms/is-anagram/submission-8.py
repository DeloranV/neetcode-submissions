class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t): return False
        s_hash_table = [0] * 26
        t_hash_table = [0] * 26

        for i in range(len(s)):
            s_hash_table[ord(s[i]) - ord('a')] += 1
            t_hash_table[ord(t[i]) - ord('a')] += 1

        return s_hash_table == t_hash_table