# Leetcode no.75 Sort Colors

class Solution:
    def sortColors(self, nums: [int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        j, k = 0, 0
        for idx in range(len(nums)):
            if nums[idx] == 1:
                nums[idx], nums[k] = nums[k], nums[idx]
                k = k + 1
            if nums[idx] == 0:
                nums[idx], nums[k] = nums[k], nums[idx]
                nums[j], nums[k] = nums[k], nums[j]
                j, k = j+1, k+1


sol = Solution()
sol.sortColors([2, 0, 2, 1, 1, 0])
sol.sortColors([2, 0, 1])
sol.sortColors([1])
sol.sortColors([0])
