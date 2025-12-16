class Solution:
    def rowAndMaximumOnes(self, mat: List[List[int]]) -> List[int]:
        maxcnt = 0
        n = len(mat)
        m = len(mat[0])

        idx = 0

        for i in range(n):
            onescnt = 0
            for j in range(m):
                onescnt += mat[i][j]
            if onescnt > maxcnt:
                maxcnt = onescnt
                idx = i
                
   
        return [idx, maxcnt]   

        