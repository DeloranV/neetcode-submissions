# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy_head = ListNode()
        iterator = dummy_head

        while list1 and list2:
            if list1.val <= list2.val:
                iterator.next = list1
                list1 = list1.next
            else:
                iterator.next = list2
                list2 = list2.next
            iterator = iterator.next
        if not list1: iterator.next = list2
        else: iterator.next = list1

        return dummy_head.next