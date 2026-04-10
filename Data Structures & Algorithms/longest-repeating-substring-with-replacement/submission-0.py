class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        counter = {}
        l = 0
        longest = 0

        for r in range(len(s)):
            counter[s[r]] = counter.get(s[r], 0) + 1
            req_replacements = (r - l + 1) - max(counter.values())
            while req_replacements > k:
                counter[s[l]] -= 1
                l += 1
                req_replacements = (r - l + 1) - max(counter.values())
            longest = max(longest, r - l + 1)
        
        return longest