class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        res = []
        mpp = {}

        for i in nums:
            mpp[i] = mpp.get(i, 0) + 1

        for d in mpp:
            if mpp[d] > (len(nums)//3):
                res.append(d)

        return res            
        