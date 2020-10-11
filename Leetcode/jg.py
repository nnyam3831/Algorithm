# Leetcode no.55 Jump Game
class Solution:
    def canJump(self, nums: [int]) -> bool:
        maxNum = 0
        for i in range(len(nums)):
            if i > maxNum:
                return False
            maxNum = max(maxNum, i + nums[i])

        return True


sol = Solution()
print(sol.canJump([2, 3, 1, 1, 4]))
print(sol.canJump([3, 2, 1, 0, 4]))
print(sol.canJump([0, 1]))
print(sol.canJump([5, 0, 0, 0, 0, 0]))
