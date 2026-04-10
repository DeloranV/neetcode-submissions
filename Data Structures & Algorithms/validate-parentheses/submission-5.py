class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        close_to_open = {")" : "(", "}" : "{", "]" : "["}

        for c in s:
            if c in close_to_open.values(): stack.append(c)
            else:
                if not stack or close_to_open[c] != stack.pop(): return False
        
        return not stack