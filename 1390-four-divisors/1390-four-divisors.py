class Solution:
    def sumIfFourDivisors(self, num):
        divisors = 0
        sum = 0

        div = 1
        while div * div <= num:
            if num % div == 0:
                other = num // div

                if div == other:
                    divisors += 1
                    sum += div
                else:
                    divisors += 2
                    sum += div + other

            if divisors > 4:
                return 0

            div += 1

        return sum if divisors == 4 else 0

    def sumFourDivisors(self, nums):
        result = 0

        for num in nums:
            result += self.sumIfFourDivisors(num)

        return result
