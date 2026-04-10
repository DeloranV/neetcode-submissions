class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        bracket_mapping = {")" : "(", "}" : "{", "]" : "["}

        for c in s:
            if c in bracket_mapping:
                if not stack or bracket_mapping[c] != stack.pop(): return False
            else: stack.append(c)
        
        return len(stack) == 0