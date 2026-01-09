# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.mp = {}
        self.maxD = 0

        def depth(node, d):
            if not node:
                return
            self.maxD = max(self.maxD, d)
            self.mp[node.val] = d
            depth(node.left, d + 1)
            depth(node.right, d + 1)

        def LCA(node):
            if not node or self.mp[node.val] == self.maxD:
                return node

            left = LCA(node.left)
            right = LCA(node.right)

            if left and right:
                return node
            return left if left else right

        depth(root, 0)
        return LCA(root)
