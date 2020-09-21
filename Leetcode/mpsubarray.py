# leetcode no.152

class Solution:
    def maxProduct(self, nums) -> int:
        r_nums = list(reversed(nums))
        for i in range(1, len(nums)):
            nums[i] *= (nums[i-1] or 1)
            r_nums[i] *= (r_nums[i-1] or 1)
        return max(nums+r_nums)


s = Solution()
print(s.maxProduct([2, 3, -2, 4]))
print(s.maxProduct([-2, 0, -1]))
