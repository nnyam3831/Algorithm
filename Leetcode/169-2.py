# Leetcode no.169 Majority Element
# O(n) time and O(1) space
# 어차피 n / 2 만큼 갖고있기 때문에 빈도만 체크하면
# 결국 major만 살아남음
class Solution:
    def majorityElement(self, nums: [int]) -> int:
        major, count = nums[0], 1

        for i in range(1, len(nums)):
            if count == 0:
                count += 1
                major = nums[i]
                continue

            if major == nums[i]:
                count += 1
                continue

            count -= 1

        return major


sol = Solution()
print(sol.majorityElement([3, 2, 3]))
print(sol.majorityElement([2, 2, 1, 1, 1, 2, 2]))
