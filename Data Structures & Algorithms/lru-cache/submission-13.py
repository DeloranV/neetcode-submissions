class DoublyLinkedNode:
    def __init__(self, key=None, val=0, next=None, prev=None):
        self.key = key
        self.val = val
        self.next = next
        self.prev = prev

class LRUCache:
    def __init__(self, capacity: int):
        self.cache = {}
        self.LRU, self.MRU = DoublyLinkedNode(), DoublyLinkedNode()
        self.LRU.next, self.MRU.prev = self.MRU, self.LRU
        self.available_space = capacity

    def insert_at_mru(self, key, value):
        newNode = DoublyLinkedNode(key=key, val=value, next=self.MRU, prev=self.MRU.prev)
        self.cache[key] = newNode
        self.MRU.prev, newNode.prev.next = newNode, newNode
        self.available_space -= 1

    def remove(self, key):
        removed = self.cache[key]
        removed.prev.next = removed.next
        removed.next.prev = removed.prev
        self.cache.pop(key)
        self.available_space += 1

    def get(self, key: int) -> int:
        if key not in self.cache: return -1
        result = self.cache[key]
        self.remove(result.key)
        self.insert_at_mru(key, result.val)
        return result.val

    def put(self, key: int, value: int) -> None:
        if key in self.cache: self.remove(key)
        elif self.available_space <= 0: self.remove(self.LRU.next.key)
        self.insert_at_mru(key, value)