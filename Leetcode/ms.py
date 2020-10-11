class Solution:
    def maxSubArray(self, nums: [int]) -> int:
        for i in range(1, len(nums)):
            if nums[i-1] > 0:
                nums[i] += nums[i-1]

        return max(nums)


sol = Solution()
print(sol.maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4]))
print(sol.maxSubArray([1]))
print(sol.maxSubArray([0]))
print(sol.maxSubArray([-1]))
print(sol.maxSubArray([-2147483647]))
