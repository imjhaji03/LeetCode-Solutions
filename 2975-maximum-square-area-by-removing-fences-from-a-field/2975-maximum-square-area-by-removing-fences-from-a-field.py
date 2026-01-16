class Solution:
    def maximizeSquareArea(self, m: int, n: int, hFences: List[int], vFences: List[int]) -> int:
        MOD = 10**9 + 7

        hFences.append(1)
        hFences.append(m)
        vFences.append(1)
        vFences.append(n)

        hFences.sort()
        vFences.sort()

        widths = set()
        for i in range(len(vFences)):
            for j in range(i + 1, len(vFences)):
                widths.add(vFences[j] - vFences[i])

        maxSide = 0
        for i in range(len(hFences)):
            for j in range(i + 1, len(hFences)):
                height = hFences[j] - hFences[i]
                if height in widths:
                    maxSide = max(maxSide, height)

        if maxSide == 0:
            return -1
        return (maxSide * maxSide) % MOD