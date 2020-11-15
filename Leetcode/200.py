# Leetcode no.200 Number of Islands

class Solution:
    def numIslands(self, grid: [[str]]) -> int:
        if not grid:
            return 0

        visited = [[0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
        dy, dx = [0, 0, 1, -1], [1, -1, 0, 0]

        def _dfs(y, x, _visited):
            if _visited[y][x]:
                return

            _visited[y][x] = 1

            for dir in range(4):
                ny = y + dy[dir]
                nx = x + dx[dir]

                if ny < 0 or ny >= len(grid) or nx < 0 or nx >= len(grid[0]):
                    continue

                if grid[ny][nx] == '1':
                    _dfs(ny, nx, _visited)

            return

        ret = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if not visited[i][j] and grid[i][j] == '1':
                    ret += 1
                    _dfs(i, j, visited)

        return ret


sol = Solution()
print(sol.numIslands([
    ["1", "1", "1", "1", "0"],
    ["1", "1", "0", "1", "0"],
    ["1", "1", "0", "0", "0"],
    ["0", "0", "0", "0", "0"]
]))

print(sol.numIslands([
    ["1", "1", "0", "0", "0"],
    ["1", "1", "0", "0", "0"],
    ["0", "0", "1", "0", "0"],
    ["0", "0", "0", "1", "1"]
]))
