class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2): return False
        char_count = [0] * 26
        for c in s1:
            n_c = self.normalized_ord(c)
            char_count[n_c] += 1

        window_count = [0] * 26
        window_len = len(s1)
        l, r = 0, -1
            
        while r < len(s2):
            while r < (window_len - 1):
                r += 1
                n_c = self.normalized_ord(s2[r])
                window_count[n_c] += 1
            n_c_l = self.normalized_ord(s2[l])
            if char_count == window_count: return True
            window_count[n_c_l] -= 1
            l += 1
            r += 1
            if r == len(s2): break
            n_c_r = self.normalized_ord(s2[r])
            window_count[n_c_r] += 1
            print(window_count)
            
        return False

    def normalized_ord(self, c):
        return (ord(c) - ord('a'))