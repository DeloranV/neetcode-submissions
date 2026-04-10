class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded = ""
        for s in strs:
            encoded += f"{len(s)}#" + s
        return encoded

    def decode(self, s: str) -> List[str]:
        res, i = [], 0
        while i < len(s):
            j = i
            while s[j] != "#":
                j += 1
            str_length = int(s[i:j])
            res.append(s[j + 1: j + 1 + str_length])
            i = j + 1 + str_length
        return res