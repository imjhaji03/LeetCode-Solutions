class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        n = len(nums)

        lst = [0]*n

        for i in range(n):
            shift = nums[i] % n
            newidx = (i + shift) % n

            if(newidx < 0):
                newidx += n

            lst[i] = nums[newidx]


        return lst        
        