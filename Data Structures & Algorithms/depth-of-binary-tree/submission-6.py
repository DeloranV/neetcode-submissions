# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        queue = deque([root])
        max_depth = 0

        while queue and root:
            for i in range(len(queue)):
                front = queue.popleft()
                if front.left: queue.append(front.left)
                if front.right: queue.append(front.right)
            max_depth += 1

        return max_depth
