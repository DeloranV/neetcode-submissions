class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        window_counter = {}
        longest = 0
        l = 0

        for r in range(len(s)):
            window_counter[s[r]] = window_counter.get(s[r], 0) + 1
            req_replacements = len(s[l:r + 1]) - max(window_counter.values())
            while req_replacements > k:
                window_counter[s[l]] -= 1
                l += 1
                req_replacements = len(s[l:r + 1]) - max(window_counter.values())
            longest = max(longest, len(s[l:r + 1]))

        return longest