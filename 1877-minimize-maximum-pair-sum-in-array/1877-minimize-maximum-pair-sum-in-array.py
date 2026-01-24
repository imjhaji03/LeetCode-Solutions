class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        
        max_result = 0
        i = 0
        j = len(nums) - 1
        
        while i < j:
            current_sum = nums[i] + nums[j]
            
            if current_sum > max_result:
                max_result = current_sum
                
            i += 1
            j -= 1
            
        return max_result