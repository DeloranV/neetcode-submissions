"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        old_to_new = {}

        old_iterator = head
        while old_iterator:
            deep_copy = Node(x=old_iterator.val)
            old_to_new[old_iterator] = deep_copy
            old_iterator = old_iterator.next
        
        old_iterator = head
        while old_iterator:
            if old_iterator.next: old_to_new[old_iterator].next = old_to_new[old_iterator.next]
            if old_iterator.random: old_to_new[old_iterator].random = old_to_new[old_iterator.random]
            old_iterator = old_iterator.next

        return old_to_new[head] if head else None