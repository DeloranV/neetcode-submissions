class Solution:
    def isPalindrome(self, s: str) -> bool:
        al_range = range(ord('a'), ord('z') + 1)
        num_range = range(ord('0'), ord('9') + 1)
        l = 0
        r = len(s) - 1
        print(al_range, num_range, sep="\n")

        while l < r:
            if (ord(s[l].lower()) not in al_range
                and ord(s[l]) not in num_range): 
                l += 1
                continue
            if (ord(s[r].lower()) not in al_range
                and ord(s[r]) not in num_range):
                r -= 1
                continue
            if s[l].lower() != s[r].lower(): return False
            l += 1
            r -= 1
        return True