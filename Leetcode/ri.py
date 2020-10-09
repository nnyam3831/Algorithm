# Leetcode no.48 Rotate Image

class Solution:
    def rotate(self, matrix: [[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        size, pos = len(matrix), 0
        while size >= 2:
            for x in range(0, size-1):
                temp = matrix[pos][pos+x]
                matrix[pos][pos+x] = matrix[pos+size-1-x][pos]
                matrix[pos+size-1-x][pos] = matrix[pos+size-1][pos+size-1-x]
                matrix[pos+size-1][pos+size-1-x] = matrix[pos+x][pos+size-1]
                matrix[pos+x][pos+size-1] = temp
            size -= 2
            pos += 1

        return


sol = Solution()
sol.rotate([[5, 1, 9, 11], [2, 4, 8, 10], [13, 3, 6, 7], [15, 14, 12, 16]])
sol.rotate([[1]])
sol.rotate([[1, 2], [3, 4]])
