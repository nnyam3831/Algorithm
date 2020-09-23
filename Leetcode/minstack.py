class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.min_stack = []

    def push(self, x: int) -> None:
        if len(self.stack) == 0:
            self.stack.append(x)
            self.min_stack.append(x)
            return

        top = self.min_stack[-1]
        if x <= top:
            self.min_stack.append(x)
        self.stack.append(x)

    def pop(self) -> None:
        if len(self.stack) == 0:
            return
        top = self.min_stack[-1]
        if top == self.stack[-1]:
            self.min_stack.pop()
        self.stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]

    def print(self):
        print(self.min_stack, self.stack)


obj = MinStack()
obj.push(-2)
obj.push(0)
obj.push(-3)
print(obj.getMin())
obj.pop()
print(obj.top())
print(obj.getMin())
