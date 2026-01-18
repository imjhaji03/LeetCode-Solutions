class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        
        row_sum = [[0] * (n + 1) for _ in range(m)]
        col_sum = [[0] * n for _ in range(m + 1)]
        
        for r in range(m):
            for c in range(n):
                row_sum[r][c+1] = row_sum[r][c] + grid[r][c]
                col_sum[r+1][c] = col_sum[r][c] + grid[r][c]
                
        def is_magic(r, c, k):
            target = row_sum[r][c + k] - row_sum[r][c]
            
            for i in range(r + 1, r + k):
                if row_sum[i][c + k] - row_sum[i][c] != target:
                    return False
            
            for j in range(c, c + k):
                if col_sum[r + k][j] - col_sum[r][j] != target:
                    return False
            
            diag1 = 0
            for i in range(k):
                diag1 += grid[r + i][c + i]
            if diag1 != target:
                return False
            
            diag2 = 0
            for i in range(k):
                diag2 += grid[r + i][c + k - 1 - i]
            if diag2 != target:
                return False
                
            return True

        for k in range(min(m, n), 1, -1):
            for r in range(m - k + 1):
                for c in range(n - k + 1):
                    if is_magic(r, c, k):
                        return k
                        
        return 1