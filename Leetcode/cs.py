# leetcode no.39 Combination Sum
class Solution:
    def combinationSum(self, candidates: [int], target: int) -> [[int]]:
        ret = []

        def _dfs(buffer, sum, index):
            if sum >= target:
                if sum == target:
                    ret.append(buffer)
                return
            not_included_buffer = buffer + [candidates[index]]
            for idx in range(index, len(candidates) - 1):
                included_buffer = buffer + [candidates[idx + 1]]
                _dfs(included_buffer, sum + candidates[idx + 1], idx + 1)
            _dfs(not_included_buffer, sum + candidates[index], index)

        for index in range(len(candidates)):
            candidate = candidates[index]
            _dfs([candidate], candidate, index)

        return ret


sol = Solution()
print(sol.combinationSum([2, 3, 6, 7], 7))
print(sol.combinationSum([2, 3, 5], 8))
print(sol.combinationSum([2], 1))
print(sol.combinationSum([1], 1))
print(sol.combinationSum([1], 2))
