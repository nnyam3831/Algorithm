# Leetcode no.56 Merge Intervals
class Solution:
    def merge(self, intervals: [[int]]) -> [[int]]:
        if intervals == [] or intervals == [[]]:
            return []

        intervals.sort()
        ret, cur = [], [intervals[0][0], intervals[0][1]]
        for interval in intervals:
            if cur[1] >= interval[0]:
                cur += interval
                cur = [cur[0], max(cur)]
            else:
                ret.append(cur)
                cur = interval

        ret.append(cur)

        return ret


sol = Solution()
print(sol.merge([[1, 3], [2, 6], [8, 10], [15, 18]]))
print(sol.merge([[1, 4], [4, 5]]))
print(sol.merge([[1, 4], [0, 4]]))
print(sol.merge([[1, 4], [2, 3]]))
print(sol.merge([[1, 4], [0, 2], [3, 5]]))
