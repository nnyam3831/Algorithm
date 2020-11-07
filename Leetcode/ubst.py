class Solution:
    def numTrees(self, n: int) -> int:
        dp = [0 for _ in range(n+1)]
        dp[0], dp[1] = 1, 1

        for i in range(2, n+1):
            for j in range(i):
                dp[i] += (dp[i-1-j] * dp[j])

        return dp[n]


sol = Solution()
print(sol.numTrees(2))
print(sol.numTrees(3))
print(sol.numTrees(4))
print(sol.numTrees(5))
