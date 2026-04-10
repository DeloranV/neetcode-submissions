class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) < 2: return False
        stack = []

        for c in s:
            if c == "(" or c == "{" or c == "[": stack.append(c)
            elif c == ")":
                if not stack or stack.pop() != "(" : return False
            elif c == "}":
                if not stack or stack.pop() != "{" : return False
            else: 
                if not stack or stack.pop() != "[" : return False

        return not stack