# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        s, f = head, head.next
        while f and f.next:
            s = s.next
            f = f.next.next
        if not s.next: return
        prev, curr, nxt = s.next, s.next, s.next.next
        s.next, curr.next = None, None

        while nxt:
            curr = nxt
            nxt = nxt.next
            curr.next = prev
            prev = curr

        l1, l2 = head, curr
        while l1 and l2:
            nxt = l1.next
            l1.next = l2
            l1 = nxt
            nxt = l2.next
            l2.next = l1
            l2 = nxt
