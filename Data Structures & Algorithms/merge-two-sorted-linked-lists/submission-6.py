# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy_head = ListNode()
        iterator = dummy_head

        while list1 or list2:
            if not list1: 
                iterator.next = list2
                break
            elif not list2: 
                iterator.next = list1
                break
            elif list1.val <= list2.val:
                iterator.next = list1
                list1 = list1.next
            else:
                iterator.next = list2
                list2 = list2.next
            iterator = iterator.next

        return dummy_head.next