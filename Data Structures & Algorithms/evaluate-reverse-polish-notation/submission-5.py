class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for token in tokens:
            if stack and token == "+":
                b = stack.pop()
                a = stack.pop()
                stack.append(a + b)
            elif stack and token == "-":
                b = stack.pop()
                a = stack.pop()
                stack.append(a - b)
            elif stack and token == "*":
                b = stack.pop()
                a = stack.pop()
                stack.append(a * b)
            elif stack and token == "/":
                b = stack.pop()
                a = stack.pop()
                stack.append(int(a / b))
            else:
                stack.append(int(token))
        
        return stack[0]