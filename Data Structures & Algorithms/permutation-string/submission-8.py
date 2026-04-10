class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2): return False
        if len(s1) == 1: return s1 in s2
        s1_counter, s2_counter = [0] * 26, [0] * 26
        l = 0

        for r in range(len(s1) - 1):
            s1_counter[ord(s1[r]) - ord('a')] += 1
            s2_counter[ord(s2[r]) - ord('a')] += 1
        s1_counter[ord(s1[-1]) - ord('a')] += 1

        for r in range(len(s1) - 1, len(s2)):
            s2_counter[ord(s2[r]) - ord('a')] += 1
            if s2_counter == s1_counter: return True
            s2_counter[ord(s2[l]) - ord('a')] -= 1
            l += 1

        return False
