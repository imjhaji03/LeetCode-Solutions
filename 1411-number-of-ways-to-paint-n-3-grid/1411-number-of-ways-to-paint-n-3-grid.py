class Solution:
    M = 10**9 + 7

    def solve(self, n, prev):
        if n == 0:
            return 1
        if self.t[n][prev] != -1:
            return self.t[n][prev]

        result = 0
        last = self.states[prev]

        for curr in range(12):
            if curr == prev:
                continue
            currPat = self.states[curr]
            conflict = False
            for col in range(3):
                if currPat[col] == last[col]:
                    conflict = True
                    break
            if not conflict:
                result = (result + self.solve(n - 1, curr)) % self.M

        self.t[n][prev] = result
        return result

    def numOfWays(self, n: int) -> int:
        self.states = ["RYG", "RGY", "RYR", "RGR", "YRG", "YGR", "YGY", "YRY", "GRY", "GYR", "GRG", "GYG"]
        self.t = [[-1] * 12 for _ in range(n)]

        result = 0
        for i in range(12):
            result = (result + self.solve(n - 1, i)) % self.M

        return result
