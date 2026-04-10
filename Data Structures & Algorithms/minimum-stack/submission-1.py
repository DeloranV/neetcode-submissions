class MinStack:

    def __init__(self):
        self.stack = []
        self.min_stack = []
        self.elem_count = 0

    def push(self, val: int) -> None:
        if self.elem_count == 0:
            self.min_stack.append(val)
        else:
            self.min_stack.append(min(self.min_stack[-1], val))
        self.stack.append(val)
        self.elem_count += 1

    def pop(self) -> None:
        self.min_stack.pop()
        self.stack.pop()
        self.elem_count -= 1

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]
