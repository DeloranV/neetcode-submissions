# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def checkBalanced(root):
            if not root: return -1

            left_height = checkBalanced(root.left) + 1
            right_height = checkBalanced(root.right) + 1
            print(left_height, right_height)

            if abs(left_height - right_height) > 1: return 50
            return max(left_height, right_height)

        return not (checkBalanced(root) > 20)
    