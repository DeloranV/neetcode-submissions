# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy_head = ListNode(next=head)
        l, r = dummy_head, dummy_head
        for i in range(n + 1): r = r.next

        while r:
            l, r = l.next, r.next
        l.next = l.next.next

        return dummy_head.next