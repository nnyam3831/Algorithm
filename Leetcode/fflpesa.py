# Leetcode 34. Find First and Last Position of Element in Sorted Array

class Solution:
    def searchRange(self, nums, target: int) -> [int]:
        ret = [-1, -1]
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        # 이렇게하면 left , right 범위를 생각해줘야 하는데
        # while left < right , and right = mid로 설정해주면 범위 안에서 돌기 때문에
        # 다른 추가 조건 안걸어도 된다
        if left < len(nums) and left >= 0 and nums[left] == target:
            ret[0] = left

        left, right = 0, len(nums) - 1

        while left <= right:
            mid = (left + right) // 2
            if nums[mid] <= target:
                left = mid + 1
            else:
                right = mid - 1
        if right < len(nums) and right >= 0 and nums[right] == target:
            ret[1] = right

        return ret


sol = Solution()
print(sol.searchRange([5, 7, 7, 8, 8, 10], 8))
print(sol.searchRange([5, 7, 7, 8, 8, 10], 6))
print(sol.searchRange([1, 2, 3, 3, 3, 6, 7, 8, 10, 10], 10))
print(sol.searchRange([], 0))
