# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        def checkSameTree(p, q):
            if not p and not q: return True
            if not p or not q or p.val != q.val: return False
            if not checkSameTree(p.left, q.left) or not checkSameTree(p.right, q.right): return False
            return True
        return checkSameTree(p, q)