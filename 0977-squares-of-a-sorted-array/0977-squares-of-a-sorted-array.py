class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        lst = []

        for i in range(len(nums)):
            lst.append((abs(nums[i])**2))

        return sorted(lst)    
        