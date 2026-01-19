class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        rows = len(mat)
        cols = len(mat[0])

        prefix = [[0] * cols for _ in range(rows)]

        for i in range(rows):
            for j in range(cols):
                prefix[i][j] = mat[i][j]
                if i > 0: prefix[i][j] += prefix[i - 1][j]
                if j > 0: prefix[i][j] += prefix[i][j - 1]
                if i > 0 and j > 0: prefix[i][j] -= prefix[i - 1][j - 1]

        def sumSquare(i, j, r2, c2):
            total = prefix[r2][c2]
            if i > 0: total -= prefix[i - 1][c2]
            if j > 0: total -= prefix[r2][j - 1]
            if i > 0 and j > 0: total += prefix[i - 1][j - 1]
            return total

        best = 0
        for i in range(rows):
            for j in range(cols):
                for k in range(best, min(rows - i, cols - j)):
                    r2, c2 = i + k, j + k
                    if sumSquare(i, j, r2, c2) <= threshold:
                        best = k + 1
                    else:
                        break
                        
        return best