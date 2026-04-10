class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_length = 0
        unique_chars = set()
        l, r = 0, 0

        while r < len(s):
            if s[r] in unique_chars:
                unique_chars.remove(s[l])
                l += 1
                continue
            max_length = max(max_length, len(s[l:r]) + 1)
            unique_chars.add(s[r])
            r += 1

        return max_length