class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        n = len(nums)
        if n == 0:
            return 0
            
        nums.sort()
        
        max_len = 0
        i = 0
        
        for j in range(n):
            while i < j and nums[j] > k * nums[i]:
                i += 1
            
            max_len = max(max_len, j - i + 1)
            
        return n - max_len