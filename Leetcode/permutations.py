# Leetcode no.46 Permutations
class Solution:
    def permute(self, nums: [int]) -> [[int]]:
        hang = [0 for _ in range(len(nums))]
        ret = []

        def _dfs(buffer):
            if len(buffer) == len(nums):
                ret.append(buffer)
                return

            for i in range(len(nums)):
                if not hang[i]:
                    hang[i] = 1
                    _dfs(buffer + [nums[i]])
                    hang[i] = 0

        _dfs([])
        return ret


sol = Solution()
print(sol.permute([1, 2, 3]))
