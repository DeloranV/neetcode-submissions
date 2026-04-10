class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2): return False
        s1_counter, window_counter = [0] * 26, [0] * 26
        l = 0

        for r in range(len(s1) - 1):
            s1_counter[ord(s1[r]) - ord('a')] += 1
            window_counter[ord(s2[r]) - ord('a')] += 1
            r += 1
        s1_counter[ord(s1[-1]) - ord('a')] += 1

        for r in range(len(s1) - 1, len(s2)):
            window_counter[ord(s2[r]) - ord('a')] += 1
            if s1_counter == window_counter: return True
            window_counter[ord(s2[l]) - ord('a')] -= 1
            l += 1
        
        return False