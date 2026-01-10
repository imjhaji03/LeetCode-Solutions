class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        m, n = len(s1), len(s2)
        dp = [[-1] * (n + 1) for _ in range(m + 1)]
        
        def solve(i, j):
            if i >= m and j >= n:
                return 0
            
            if dp[i][j] != -1:
                return dp[i][j]
            
            if i >= m:
                dp[i][j] = ord(s2[j]) + solve(i, j + 1)
                return dp[i][j]
            
            if j >= n:
                dp[i][j] = ord(s1[i]) + solve(i + 1, j)
                return dp[i][j]
            
            if s1[i] == s2[j]:
                dp[i][j] = solve(i + 1, j + 1)
            else:
                delete_s1 = ord(s1[i]) + solve(i + 1, j)
                delete_s2 = ord(s2[j]) + solve(i, j + 1)
                dp[i][j] = min(delete_s1, delete_s2)
            
            return dp[i][j]
        
        return solve(0, 0)
