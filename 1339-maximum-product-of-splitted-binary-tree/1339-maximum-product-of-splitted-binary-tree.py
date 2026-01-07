# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        MOD = 10**9 + 7
        self.totalSum = 0
        self.maxP = 0

        def dfs(node):
            if not node:
                return 0

            left = dfs(node.left)
            right = dfs(node.right)
            curr = node.val + left + right

            self.maxP = max(self.maxP, (self.totalSum - curr) * curr)
            return curr
        self.totalSum = dfs(root)
        dfs(root)

        return self.maxP % MOD
        