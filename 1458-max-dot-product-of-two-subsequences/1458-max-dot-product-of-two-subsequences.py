class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        self.m = len(nums1)
        self.n = len(nums2)
        
        NEG_INF = -10**9
        dp = [[NEG_INF] * (self.n + 1) for _ in range(self.m + 1)]
        
        def solve(i: int, j: int) -> int:
            if i == self.m or j == self.n:
                return NEG_INF  
            
            if dp[i][j] != NEG_INF:
                return dp[i][j]
            
            val = nums1[i] * nums2[j]
            
            take_i_j = solve(i + 1, j + 1) + val
            take_i   = solve(i, j + 1)
            take_j   = solve(i + 1, j)
            
            dp[i][j] = max(val, take_i_j, take_i, take_j)
            return dp[i][j]
        
        return solve(0, 0)