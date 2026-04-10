class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l, r = 0, 0
        longest = 0
        chars = set()

        while r < len(s):
            if s[r] in chars:
                chars.remove(s[l])
                l += 1
                continue
            longest = max(longest, len(s[l:r]) + 1)
            chars.add(s[r])
            r += 1
        return longest