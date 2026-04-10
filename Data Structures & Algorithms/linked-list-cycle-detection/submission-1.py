# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        hashed_nodes = set()
        iterator = head

        while iterator:
            if iterator in hashed_nodes: return True
            hashed_nodes.add(iterator)
            iterator = iterator.next

        return False
