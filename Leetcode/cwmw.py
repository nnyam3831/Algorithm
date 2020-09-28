# leetcode no.11 Container With Most Water
class Solution:
    def maxArea(self, height) -> int:
        left, right = 0, len(height) - 1
        ret = 0
        while left < right:
            ret = max(ret, (right - left) * min(height[left], height[right]))
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return ret


s = Solution()
input = [1, 8, 6, 2, 5, 4, 8, 3, 7]
input2 = [5, 5, 5, 5, 5, 5, 5]
print(s.maxArea(input))
print(s.maxArea(input2))
