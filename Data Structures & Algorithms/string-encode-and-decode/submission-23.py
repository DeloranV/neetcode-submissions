class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded = ""
        for s in strs:
            encoded += str(len(s)) + "#" + s
        return encoded

    def decode(self, s: str) -> List[str]:
        res = []
        i = 0
        while i < len(s):
            res.append("")
            j = i
            while s[j] != "#":
                j += 1
            str_len = int(s[i:j])
            i = j + 1
            while str_len > 0:
                res[-1] += s[i]
                str_len -= 1
                i += 1

        return res