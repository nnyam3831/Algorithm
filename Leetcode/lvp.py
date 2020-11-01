# Leetcode no.32 Longest Valid Parentheses

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        dp = [0 for _ in range(len(s))]

        ret, temp, fixed = 0, 0, 0
        for i in range(len(s)):
            if i == 0:
                dp[i] = 1 if s[i] == "(" else -1
                continue

            if s[i] == "(":
                dp[i] = dp[i-1] + 1 if dp[i-1] >= 0 else 1
            else:
                dp[i] = dp[i-1] - 1
                if dp[i] > 0:
                    temp += 2
                elif dp[i] == 0:
                    fixed = temp
                else:
                    ret = max(ret, fixed)
                    fixed = 0
                    temp = 0
        if fixed == 0:
            fixed = temp

        ret = max(ret, fixed)
        return ret


sol = Solution()

print(sol.longestValidParentheses("(()"))
print(sol.longestValidParentheses(")()())"))
print(sol.longestValidParentheses(""))
print(sol.longestValidParentheses("(((())"))
print(sol.longestValidParentheses("(())))("))
print(sol.longestValidParentheses("(()))))()()()()()()"))
print(sol.longestValidParentheses("()(()"))
