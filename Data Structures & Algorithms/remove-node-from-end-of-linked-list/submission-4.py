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

        n_node = length - n
        dummy_node = ListNode(next = head)
        iterator = dummy_node
        for i in range(n_node): iterator = iterator.next
        remove = iterator.next
        iterator.next = remove.next

        return dummy_node.next