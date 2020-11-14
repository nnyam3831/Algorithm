# Leetcode no.10 Regular Expression Matching
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if len(p) == 0:
            return len(s) == 0

        if len(p) >= 2 and p[1] == "*":
            return self.isMatch(s, p[2:]) or (len(s) != 0 and (s[0] == p[0] or '.' == p[0]) and self.isMatch(s[1:], p))
        else:
            return len(s) != 0 and (s[0] == p[0] or '.' == p[0]) and self.isMatch(s[1:], p[1:])


sol = Solution()
print(sol.isMatch("aa", "a"))
print(sol.isMatch("aa", "a*"))
print(sol.isMatch("ab", ".*"))
print(sol.isMatch("aab", "c*a*b"))
print(sol.isMatch("mississippi", "mis*is*p*."))
print(sol.isMatch("ab", ".*c"))
print(sol.isMatch("aaa", "aaaa"))
