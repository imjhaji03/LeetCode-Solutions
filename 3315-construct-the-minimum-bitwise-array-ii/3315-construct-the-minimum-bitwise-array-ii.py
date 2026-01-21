class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        ans = []
        for n in nums:
            if n == 2:
                ans.append(-1)
            else:
                first_zero_bit = (~n & (n + 1))
                target_bit = first_zero_bit >> 1
                ans.append(n ^ target_bit)
        return ans