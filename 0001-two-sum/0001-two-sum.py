class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        mpp = {}
        for i in range(n):
            diff = target - nums[i]
            if diff in mpp:
                return [mpp[diff], i]

            mpp[nums[i]] = i        
        return []    