class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix or not matrix[0]:
            return 0
        
        n = len(matrix)
        m = len(matrix[0])
        
        def get_nsl(heights):
            size = len(heights)
            left = [0] * size
            stack = []
            pseudo_index = -1
            
            for i in range(size):
                while stack and heights[stack[-1]] >= heights[i]:
                    stack.pop()
                if not stack:
                    left[i] = pseudo_index
                else:
                    left[i] = stack[-1]
                stack.append(i)
            return left

        def get_nsr(heights):
            size = len(heights)
            right = [0] * size
            stack = []
            pseudo_index = size
            
            for i in range(size - 1, -1, -1):
                while stack and heights[stack[-1]] >= heights[i]:
                    stack.pop()
                if not stack:
                    right[i] = pseudo_index
                else:
                    right[i] = stack[-1]
                stack.append(i)
            return right

        def mah(heights):
            size = len(heights)
            left = get_nsl(heights)
            right = get_nsr(heights)
            
            max_area = 0
            for i in range(size):
                width = right[i] - left[i] - 1
                max_area = max(max_area, heights[i] * width)
            return max_area

        heights = [0] * m
        maxA = 0
        
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == '0':
                    heights[j] = 0
                else:
                    heights[j] += 1
            
            maxA = max(maxA, mah(heights))
            
        return maxA