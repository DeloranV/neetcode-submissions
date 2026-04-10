# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        s, f = head, head.next

        while s != f:
            if not f or not f.next: return False
            s, f = s.next, f.next.next

        return True