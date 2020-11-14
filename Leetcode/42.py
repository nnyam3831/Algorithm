# Leetcode no.42 Trapping Rain Water
class Solution:
    def trap(self, height: [int]) -> int:
        left, right = 0, len(height) - 1
        ret, max_left, max_right = 0, 0, 0

        while left <= right:
            if height[left] <= height[right]:
                if height[left] >= max_left:
                    max_left = height[left]
                else:
                    ret += max_left - height[left]
                left += 1
            else:
                if height[right] >= max_right:
                    max_right = height[right]
                else:
                    ret += max_right - height[right]
                right -= 1

        return ret


sol = Solution()
print(sol.trap([4, 2, 0, 3, 2, 5]))
print(sol.trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]))
