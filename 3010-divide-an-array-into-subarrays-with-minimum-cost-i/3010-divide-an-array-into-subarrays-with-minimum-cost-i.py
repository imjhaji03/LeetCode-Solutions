class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        first_min = nums[0]
        second_min = float('inf')
        third_min = float('inf')
        
        for i in range(1, len(nums)):
            if nums[i] < second_min:
                third_min = second_min
                second_min = nums[i]
            elif nums[i] < third_min:
                third_min = nums[i]
                
        return first_min + second_min + third_min