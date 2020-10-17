# 추가적으로 2차원 리스트를 복사하는데 cost가 꽤 먹음
# 그냥 한 번 돌면서 복구시키는게 더 좋을듯
class Solution:
    def exist(self, board: [[str]], word: str) -> bool:
        dy, dx = [0, 0, -1, 1], [1, -1, 0, 0]
        m, n = len(board), len(board[0])

        def _dfs(y, x, word, index):
            if board[y][x] != word[index]:
                return False

            if board[y][x] == word[index] and index == len(word) - 1:
                return True

            ret = False
            temp, board[y][x] = board[y][x], "#"
            for dir in range(4):
                if ret:
                    return ret
                ny, nx = y + dy[dir], x + dx[dir]
                if ny >= m or ny < 0 or nx >= n or nx < 0:
                    continue

                ret = ret or _dfs(ny, nx, word, index + 1)

            board[y][x] = temp
            return ret

        for i in range(m):
            for j in range(n):
                if _dfs(i, j, word, 0):
                    return True

        return False


sol = Solution()
print(sol.exist([["A", "B", "C", "E"], ["S", "F", "C", "S"],
                 ["A", "D", "E", "E"]], "ABCCED"))
print(sol.exist([["A", "B", "C", "E"], [
      "S", "F", "C", "S"], ["A", "D", "E", "E"]], "SEE"))
print(sol.exist([["A", "B", "C", "E"], [
      "S", "F", "C", "S"], ["A", "D", "E", "E"]], "ABCB"))
print(sol.exist([["C", "A", "A"], ["A", "A", "A"], ["B", "C", "D"]], "AAB"))
