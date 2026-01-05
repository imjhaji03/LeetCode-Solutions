class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:

        r = len(matrix)
        c = len(matrix[0])

        negcnt = 0
        res = 0
        smallest = float('inf')

        for i in range(r):
            for j in range(c):
                val = matrix[i][j]
                res += abs(val)

                if val < 0:
                    negcnt += 1

                smallest = min(smallest, abs(val))

        if negcnt % 2 == 0:
            return res
        else:
            return res - 2 * smallest
