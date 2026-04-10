# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        s, f = head, head.next
        while f and f.next: s, f = s.next, f.next.next
        
        prev, curr = None, s
        while curr:
            next = curr.next
            curr.next = prev
            prev, curr = curr, next

        l, r = head, prev
        while l != r and l and r:
            next = l.next
            l.next = r
            l = next
            next = r.next
            r.next = l
            r = next