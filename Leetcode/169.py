# Leetcode no.169 Majority Element

class Solution:
    def majorityElement(self, nums: [int]) -> int:
        table, l, ret = {}, len(nums), 0

        for num in nums:
            if num not in table:
                table[num] = 0

            table[num] += 1

            if table[num] > l // 2:
                ret = num
                break

        return ret


sol = Solution()
print(sol.majorityElement([3, 2, 3]))
print(sol.majorityElement([2, 2, 1, 1, 1, 2, 2]))
