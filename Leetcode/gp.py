# leetcode no.22 Generate Parentheses
# 따로 스택쓸거없이 l count, l remain를 넣으면 됨 and dfs
# 결국 ( 추가냐 ) 추가냐 2개니깐 nCn/2

class Solution:
    def generateParenthesis(self, n: int):
        ret = []

        def dfs(count, remain, current):
            if len(current) == 2*n:
                ret.append(current)
                return
            if count != 0:
                dfs(count-1, remain+1, current + "(")
            if remain != 0:
                dfs(count, remain-1, current + ")")
            return

        dfs(n, 0, "")

        return ret


sol = Solution()
input1 = 3
print(sol.generateParenthesis(input1))
print(sol.generateParenthesis(1))
print(sol.generateParenthesis(2))
print(sol.generateParenthesis(4))
