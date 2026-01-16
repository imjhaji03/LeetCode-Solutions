class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        n = len(nums)
        i = 0
        j = 1

        while(i < n and j < n):
            if(nums[i] == 0 and nums[j] != 0):
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
                j += 1
            elif(nums[i] == 0 and nums[j] == 0):
                j += 1    
            else:
                i += 1
                j += 1
        return nums        
    
        