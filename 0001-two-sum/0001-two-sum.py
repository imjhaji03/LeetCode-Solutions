class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mpp = {}
        for i in range(len(nums)):
            req = target - nums[i]
            if req in mpp:
                return [mpp[req], i]
            mpp[nums[i]] = i
        return []        
        