# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        max_diameter = 0

        def DFS(root):
            nonlocal max_diameter

            if not root: return -1

            left = 1 + DFS(root.left)
            right = 1 + DFS(root.right)

            max_diameter = max(max_diameter, left + right)

            return max(left, right)

        DFS(root)
        return max_diameter