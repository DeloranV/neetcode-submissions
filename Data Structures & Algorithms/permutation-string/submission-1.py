class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        char_count = [0] * 26
        permutation = False
        for c in s1:
            n_c = self.normalized_ord(c)
            char_count[n_c] += 1

        window_count = [0] * 26
        window_len = len(s1)
        l = 0

        for r in range(window_len - 1):
            n_c = self.normalized_ord(s2[r])
            window_count[n_c] += 1
        
        r = window_len - 1
        while r < len(s2):
            n_c_r = self.normalized_ord(s2[r])
            n_c_l = self.normalized_ord(s2[l])
            window_count[n_c_r] += 1
            print(window_count)
            if char_count == window_count: permutation = True
            window_count[n_c_l] -= 1
            l += 1
            r += 1
        return permutation

    def normalized_ord(self, c):
        return (ord(c) - ord('a'))