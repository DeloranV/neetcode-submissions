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

        iterator = head
        while iterator: 
            old_to_new[iterator] = Node(x=iterator.val)
            iterator = iterator.next

        iterator = head
        while iterator:
            if iterator.random: old_to_new[iterator].random = old_to_new[iterator.random]
            if iterator.next: old_to_new[iterator].next = old_to_new[iterator.next]
            iterator = iterator.next

        return old_to_new[head] if head else None