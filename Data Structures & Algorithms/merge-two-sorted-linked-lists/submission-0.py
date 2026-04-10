# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        l1, l2 = list1, list2
        if not l1: return l2
        if not l2: return l1
        if l1.val < l2.val:
            head = ListNode(next=l1)
            l1 = l1.next
        else:
            head = ListNode(next=l2)
            l2 = l2.next
        i = head.next

        while l1 and l2:
            if l1.val < l2.val:
                i.next = l1
                l1 = l1.next
                i = i.next
            else:
                i.next = l2
                l2 = l2.next
                i = i.next
        if not l1: i.next = l2
        if not l2: i.next = l1
        return head.next