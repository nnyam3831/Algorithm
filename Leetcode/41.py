# Leetcode no.41 First Missing Positive
# O(n) time and O(1) extra space
class Solution:
    def firstMissingPositive(self, nums: [int]) -> int:
        # extra space: use array in place and use pointer
        # the smallest number must be within 1 ~ len(nums)+1

        nums.append(0)
        l = len(nums)
        for i in range(len(nums)):
            if nums[i] < 0 or nums[i] >= l:
                nums[i] = 0

        for i in range(len(nums)):
            nums[nums[i] % l] += l

        for i in range(len(nums)):
            if nums[i] // l == 0:
                return i

        return l


sol = Solution()
print(sol.firstMissingPositive([1, 2, 0]))
print(sol.firstMissingPositive([3, 4, -1, 1]))
print(sol.firstMissingPositive([7, 8, 9, 11, 12]))
