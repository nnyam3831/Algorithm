# Leetcode no.20 Valid Parentheses
class Solution:
    def isValid(self, s: str) -> bool:
        open = ["(", "[", "{"]
        close = [")", "]", "}"]
        stack = []

        for c in s:
            if c in open:
                stack.append(c)
                continue
            if len(stack) == 0:
                return False

            top = stack[-1]
            if open.index(top) == close.index(c):
                # match and pop
                stack.pop()
            else:
                return False

        return stack == []


sol = Solution()
print(sol.isValid("()"))
print(sol.isValid("()[]{}"))
print(sol.isValid("(]"))
print(sol.isValid("{[]}"))
