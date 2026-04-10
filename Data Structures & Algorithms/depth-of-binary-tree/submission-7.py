# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        stack = [(root, 1)]
        max_depth = 0
        
        while stack and root:
            node_depth = stack.pop()
            max_depth = max(max_depth, node_depth[1])
            if node_depth[0].right: stack.append((node_depth[0].right, node_depth[1] + 1))
            if node_depth[0].left: stack.append((node_depth[0].left, node_depth[1] + 1))

        return max_depth