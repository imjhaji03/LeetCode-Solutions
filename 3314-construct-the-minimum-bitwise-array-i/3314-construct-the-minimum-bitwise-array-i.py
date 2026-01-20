class Solution:
    def minBitwiseArray(self, nums: list[int]) -> list[int]:
        res = []
        for num in nums:
            if num % 2 == 0:
                res.append(-1)
            else:
                for i in range(1, 32):
                    if not (num & (1 << i)):
                        res.append(num ^ (1 << (i - 1)))
                        break
        return res