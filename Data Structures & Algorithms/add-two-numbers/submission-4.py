# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        l1_iter, l2_iter = l1, l2
        res_head = ListNode()

        carry = 0
        res_iter = res_head
        while l1_iter or l2_iter:
            if not l1_iter: digit_sum = 0 + l2_iter.val + carry
            elif not l2_iter: digit_sum = l1_iter.val + 0 + carry
            else: digit_sum = l1_iter.val + l2_iter.val + carry
            if carry > 0: carry -= 1
            if digit_sum > 9:
                digit_sum = digit_sum % 10
                carry += 1
            digit_sum_node = ListNode(val=digit_sum)
            res_iter.next = digit_sum_node
            if l1_iter: l1_iter = l1_iter.next
            if l2_iter: l2_iter = l2_iter.next
            res_iter = res_iter.next
        if carry > 0:
            res_iter.next = ListNode(val=carry)

        return res_head.next