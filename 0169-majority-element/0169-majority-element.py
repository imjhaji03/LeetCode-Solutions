class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        mpp = {}
        for i in nums:
            mpp[i] = mpp.get(i,0) + 1

        for d in mpp:
            if mpp[d] > (len(nums)//2):
                return d

        