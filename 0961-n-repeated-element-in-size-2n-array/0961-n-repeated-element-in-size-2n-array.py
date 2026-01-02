class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        s = set()
        for num in nums:
            if(num in s):
                return num
            else:
                s.add(num) 
                
"""        
        n = len(nums)-1
        for i in range(n):
            if((nums[i] == nums[i-1]) or (nums[i] == nums[i-2])):
                return nums[i]
        return nums[n]       

"""   
"""
        n = len(nums) // 2

        mpp = {}

        for num in nums:
            mpp[num] = mpp.get(num, 0) + 1

        for w in mpp:
            if mpp[w] >= n:
                return w    
"""

        