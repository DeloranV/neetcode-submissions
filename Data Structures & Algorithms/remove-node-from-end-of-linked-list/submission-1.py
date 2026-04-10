# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        length = 0
        
        iterator = head
        while iterator:
            length += 1
            iterator = iterator.next
        if length == 1: 
            head.next = None
            return

        n_jumps = length - n - 1
        iterator = head
        if n_jumps < 0: return head.next
        while n_jumps > 0:
            iterator = iterator.next
            n_jumps -= 1
        remove = iterator.next
        iterator.next = remove.next

        return head