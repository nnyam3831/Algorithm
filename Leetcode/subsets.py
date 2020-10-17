# Leetcode no.78 Subsets

class Solution:
    def subsets(self, nums: [int]) -> [[int]]:
        ret = []

        def _dfs(index, current, ret):
            if index >= len(nums):
                ret.append(current)
                return

            _dfs(index + 1, current + [nums[index]], ret)
            _dfs(index + 1, current, ret)

        _dfs(0, [], ret)

        return ret


sol = Solution()
print(sol.subsets([1, 2, 3]))
