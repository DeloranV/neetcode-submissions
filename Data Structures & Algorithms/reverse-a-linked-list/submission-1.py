# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev, curr, nxt = None, None, head

        while nxt:
            prev = curr
            curr = nxt
            nxt = nxt.next
            curr.next = prev
        return curr