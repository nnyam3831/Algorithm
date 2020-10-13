# Leetcode no.64 Minimum Path Sum

class Solution:
    def minPathSum(self, grid: [[int]]) -> int:
        m, n = len(grid), len(grid[0])
        sums = [[-1 for j in range(n)] for i in range(m)]

        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    sums[i][j] = grid[i][j]

                for k in range(2):
                    ny, nx = i + k, j + 1 - k
                    if ny >= m or ny < 0 or nx >= n or nx < 0:
                        continue

                    if sums[ny][nx] == -1:
                        sums[ny][nx] = sums[i][j] + grid[ny][nx]
                    else:
                        sums[ny][nx] = min(
                            sums[ny][nx],
                            sums[i][j] + grid[ny][nx]
                        )

        return sums[m-1][n-1]


sol = Solution()
print(sol.minPathSum([
    [1, 3, 1],
    [1, 5, 1],
    [4, 2, 1]
]))
