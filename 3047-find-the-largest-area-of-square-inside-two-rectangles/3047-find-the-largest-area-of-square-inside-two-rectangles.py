class Solution:
    def largestSquareArea(self, bottomLeft: List[List[int]], topRight: List[List[int]]) -> int:
        n = len(bottomLeft)
        max_side = 0

        for i in range(n):
            for j in range(i + 1, n):
                inter_bottom_x = max(bottomLeft[i][0], bottomLeft[j][0])
                inter_top_x = min(topRight[i][0], topRight[j][0])
                
                inter_bottom_y = max(bottomLeft[i][1], bottomLeft[j][1])
                inter_top_y = min(topRight[i][1], topRight[j][1])

                width = inter_top_x - inter_bottom_x
                height = inter_top_y - inter_bottom_y

                if width > 0 and height > 0:
                    side = min(width, height)
                    max_side = max(max_side, side)

        return max_side * max_side