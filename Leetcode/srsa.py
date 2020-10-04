# leetcode no.33 Search in Rotated Sorted Array
# O(logN)으로 풀 수 있는가??
# pivot을 찾고 list 2개로 나눠서 풀 수 있을듯...
# nums[i-1] > nums[i] 되는 곳이 pivot point
class Solution:
    def search(self, nums, target: int) -> int:
        # find pivot
        left, right = 0, len(nums)-1

        while right - left > 1:
            mid = (left + right) // 2
            if nums[mid] < nums[right]:
                right = mid
            else:
                left = mid
        # left, right가 pivot point
        if nums[left] >= target and nums[0] <= target:
            right = left
            left = 0
        elif nums[right] <= target and nums[-1] >= target:
            left = right
            right = len(nums)-1
        ret = -1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                ret = mid
                break
            if nums[mid] < target:
                left = mid + 1
            if nums[mid] > target:
                right = mid - 1

        return ret


sol = Solution()
print(sol.search([4, 5, 6, 7, 0, 1, 2], 0))
print(sol.search([4, 5, 6, 7, 0, 1, 2], 3))
print(sol.search([1], 0))
