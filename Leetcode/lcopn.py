# leetcode no.17 Letter Combinations of a Phone Number

class Solution:
    def letterCombinations(self, digits: str):
        if len(digits) == 0:
            return []
        dial = [[] for _ in range(10)]
        dial[2] = ["a", "b", "c"]
        dial[3] = ["d", "e", "f"]
        dial[4] = ["g", "h", "i"]
        dial[5] = ["j", "k", "l"]
        dial[6] = ["m", "n", "o"]
        dial[7] = ["p", "q", "r", "s"]
        dial[8] = ["t", "u", "v"]
        dial[9] = ["w", "x", "y", "z"]
        s = set([])

        def dfs(idx, pattern):
            if idx == len(digits):
                s.add(pattern)
                return
            for c in dial[int(digits[idx])]:
                dfs(idx + 1, pattern + c)

        dfs(0, "")
        ret = list(s)
        return ret


sol = Solution()
print(sol.letterCombinations("23"))
