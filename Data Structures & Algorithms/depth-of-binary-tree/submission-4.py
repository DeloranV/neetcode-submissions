# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root: return 0
        stack = [[root, 1]]
        res = 0

        while stack:
            temp = stack.pop()
            res = max(res, temp[1])
            if temp[0].right: stack.append([temp[0].right, temp[1] + 1])
            if temp[0].left: stack.append([temp[0].left, temp[1] + 1])

        return res