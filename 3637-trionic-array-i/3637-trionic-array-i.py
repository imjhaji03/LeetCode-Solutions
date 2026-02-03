class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        n = len(nums)
        if n < 4:
            return False
        
        soln1 = [False] * n
        soln1[0] = True
        for i in range(1, n):
            if nums[i-1] < nums[i]:
                soln1[i] = soln1[i-1]
        
        soln2 = [False] * n
        for i in range(2, n):
            if nums[i-1] > nums[i]:
                soln2[i] = soln1[i-1] or soln2[i-1]
        
        soln3 = [False] * n
        soln3[n-1] = True
        for i in range(n-2, -1, -1):
            if nums[i] < nums[i+1]:
                soln3[i] = soln3[i+1]
                
        for i in range(2, n-1):
            if soln2[i] and soln3[i]:
                return True
                
        return False