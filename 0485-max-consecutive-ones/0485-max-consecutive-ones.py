class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        count = 0
        sum = 0
        for i in range(len(nums)):
            if nums[i] == 1:
                sum += 1
                count = max(sum, count)
            else:
                sum = 0

        return count    
        