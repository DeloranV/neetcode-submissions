# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        balanced = True

        def checkHeight(root):
            nonlocal balanced
            if not root: return 0

            left = 1 + checkHeight(root.left)
            right = 1 + checkHeight(root.right)

            if abs(left - right) > 1: balanced = False
            return max(left, right)

        checkHeight(root)
        return balanced