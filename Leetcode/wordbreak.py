
# wordDict first and string first 두 가지 관점으로 생각해볼수있다.
# wordDict first로 하면 명확하게 O(N**M)인데 나처럼 string first로 생각해보면
# 파이썬은 재귀가 너무 쌓여서 터질 수도 있음(결국 끝까지 가서 확인하고 return하기때문에)
class Solution:
    def wordBreak(self, s: str, wordDict) -> bool:
        cache = [-1 for _ in range(len(s))]

        def dfs(s: str, index):
            if cache[index] != -1:
                return cache[index]
            ret = False
            for i in range(0, len(s)):
                if s[0:i+1] in wordDict:
                    if i == len(s) - 1:
                        cache[index] = True
                        return cache[index]

                    ret = ret or dfs(s[i+1:], index + i + 1)

            cache[index] = ret
            return ret

        return dfs(s, 0)


s = Solution()
print(s.wordBreak("leetcode", ["leet", "code"]))
print(s.wordBreak("applepenapple", ["apple", "pen"]))
print(s.wordBreak("catsandog", ["cats", "dog", "sand", "and", "cat"]))
# s = "123123"
