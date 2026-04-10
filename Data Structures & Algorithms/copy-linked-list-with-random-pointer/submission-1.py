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
        if not head: return
        hash_map = {}
        newHead = Node(head.val)
        old_iterator, new_iterator = head, newHead
        while old_iterator.next:
            hash_map[old_iterator] = new_iterator
            old_iterator = old_iterator.next
            newNode = Node(old_iterator.val)
            new_iterator.next = newNode
            new_iterator = new_iterator.next
        hash_map[old_iterator] = new_iterator
        old_iterator, new_iterator = head, newHead
        while old_iterator:
            new_iterator.random = hash_map[old_iterator.random] if old_iterator.random else None
            old_iterator, new_iterator = old_iterator.next, new_iterator.next
        
        return newHead