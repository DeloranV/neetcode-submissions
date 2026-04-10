class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_hash_table = [0] * 26
        t_hash_table = [0] * 26

        for char in s:
            hash_idx = ord(char) % 97
            s_hash_table[hash_idx] = s_hash_table[hash_idx] + 1

        for char in t:
            hash_idx = ord(char) % 97
            t_hash_table[hash_idx] = t_hash_table[hash_idx] + 1

        return s_hash_table == t_hash_table