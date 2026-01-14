class Solution:
    def check(self, squares: List[List[int]], mid_y: float, total: float) -> bool:
        bot_area = 0.0
        for square in squares:
            y = square[1]
            l = square[2]
            boty = y
            topy = y + l
            if mid_y >= topy:
                bot_area += l * l
            elif mid_y > boty:
                bot_area += (mid_y - boty) * l
        return bot_area >= total / 2.0

    def separateSquares(self, squares: List[List[int]]) -> float:
        low = float("inf")
        high = float("-inf")
        total = 0.0

        for square in squares:
            y = square[1]
            l = square[2]
            total += l * l
            low = min(low, y)
            high = max(high, y + l)

        result_y = 0.0

        while high - low > 1e-5:
            mid_y = low + (high - low) / 2.0
            result_y = mid_y
            if self.check(squares, mid_y, total):
                high = mid_y
            else:
                low = mid_y

        return result_y