# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        diameter = 0

        def max_diameter(root):
            nonlocal diameter

            if not root: return -1

            left_height = max_diameter(root.left) + 1
            right_height = max_diameter(root.right) + 1

            diameter = max(diameter, left_height + right_height)

            return max(left_height, right_height)

        max_diameter(root)
        return diameter