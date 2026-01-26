class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        
        result = []
        min_diff = float('inf')
        n = len(arr)
        
        for i in range(1, n):
            diff = arr[i] - arr[i-1]
            if diff < min_diff:
                min_diff = diff
        
        for i in range(1, n):
            if arr[i] - arr[i-1] == min_diff:
                result.append([arr[i-1], arr[i]])
                
        return result