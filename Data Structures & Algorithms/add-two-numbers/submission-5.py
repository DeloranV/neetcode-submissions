# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        res_head = ListNode()
        res_iter = res_head

        carry = 0
        while l1 or l2 or carry:
            num_1 = l1.val if l1 else 0
            num_2 = l2.val if l2 else 0

            digit_sum = num_1 + num_2 + carry
            carry = digit_sum // 10
            digit_sum = digit_sum % 10

            res_iter.next = ListNode(val=digit_sum)
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
            res_iter = res_iter.next

        return res_head.next