# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        end = head
        count = 0

        while end:
            if count > 1001: return True
            count += 1
            end = end.next
        
        return False