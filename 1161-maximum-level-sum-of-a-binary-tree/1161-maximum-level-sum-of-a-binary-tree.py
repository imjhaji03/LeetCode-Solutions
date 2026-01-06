# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        maxSum = float('-inf')
        resultLevel = 0
        currLevel = 1

        queue = []
        queue.append(root)

        while len(queue) > 0:
            n = len(queue)
            levelSum = 0

            while n > 0:
                node = queue.pop(0)
                levelSum += node.val

                if node.left:
                    queue.append(node.left)

                if node.right:
                    queue.append(node.right)

                n -= 1

            if levelSum > maxSum:
                maxSum = levelSum
                resultLevel = currLevel

            currLevel += 1

        return resultLevel

        