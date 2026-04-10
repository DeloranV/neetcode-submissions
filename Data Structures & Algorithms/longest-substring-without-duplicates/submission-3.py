class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        window_chars = {}
        longest = 0
        l = 0

        for r in range(len(s)):
            window_chars[s[r]] = window_chars.get(s[r], 0) + 1
            while window_chars[s[r]] > 1:
                window_chars[s[l]] -= 1
                l += 1
            longest = max(longest, len(s[l:r + 1]))

        return longest
