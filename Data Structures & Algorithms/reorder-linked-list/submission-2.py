# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        s, f = head, head
        while f and f.next:
            s, f = s.next, f.next.next
        if not s.next: return
        prev, curr, nxt = s, s, s.next
        
        while nxt:
            curr, nxt = nxt, nxt.next
            curr.next, prev = prev, curr
        s.next = None

        l1, l2 = head, curr
        while l1 != l2 and l1.next != l2:
            nxt, l1.next = l1.next, l2
            l1 = nxt
            nxt, l2.next = l2.next, l1
            l2 = nxt
