# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        prev, curr = None, l1
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        l1 = prev

        prev, curr = None, l2
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        l2 = prev

        num1 = ""
        iterator1 = l1
        while iterator1:
            num1 += str(iterator1.val)
            iterator1 = iterator1.next

        num2 = ""
        iterator2 = l2
        while iterator2:
            num2 += str(iterator2.val)
            iterator2 = iterator2.next

        added = str(int(num1) + int(num2))
        head = ListNode()
        iterator = head
        for c in added[::-1]:
            new_node = ListNode(val=int(c))
            iterator.next = new_node
            iterator = iterator.next
        return head.next