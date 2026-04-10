# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def checkBalanced(root):
            if not root: return 0

            left_height = checkBalanced(root.left)
            if left_height == -1: return -1
            right_height = checkBalanced(root.right)
            if right_height == -1: return -1
            if abs(left_height - right_height) > 1: return -1
            return max(left_height, right_height) + 1

        return checkBalanced(root) != -1