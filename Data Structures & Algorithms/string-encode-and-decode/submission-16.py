class Solution:

    def encode(self, strs: List[str]) -> str:
        if len(strs) == 0: return "--"
        res = ""
        for s in strs:
            res += s + ",|#"
        return res[:-3]

    def decode(self, s: str) -> List[str]:
        if s == "--": return []
        res = [""]
        i = 0
        while i < len(s):
            if s[i] == ",":
                if s[i+1] == "|" and s[i+2] == "#":
                    res.append("")
                    i += 3
                    continue
            res[-1] += s[i]
            i += 1
        return res
            


