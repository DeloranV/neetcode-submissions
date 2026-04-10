class DoublyLinkedNode:
    def __init__(self, key=None, val=0, next=None, prev=None):
        self.key = key
        self.val = val
        self.next = next
        self.prev = prev

class LRUCache:
    def __init__(self, capacity: int):
        self.available_space = capacity
        self.storage = DoublyLinkedNode()
        self.storage_map = {}
        self.MRU_ptr = self.storage
        
    def remove(self, key):
        curr = self.storage_map[key]
        if curr == self.MRU_ptr: self.MRU_ptr = self.MRU_ptr.prev
        self.storage_map.pop(key)
        prev, next = curr.prev, curr.next
        if next: next.prev = prev
        prev.next = next

    def insert_tail(self, key, val):
        new_node = DoublyLinkedNode(key=key, val=val, prev=self.MRU_ptr)
        self.MRU_ptr.next = new_node
        self.MRU_ptr = self.MRU_ptr.next
        self.storage_map[key] = self.MRU_ptr

    def get(self, key: int) -> int:
        if key not in self.storage_map: return -1
        if self.storage_map[key] != self.MRU_ptr:
            removed_val = self.storage_map[key].val
            self.remove(key)
            self.insert_tail(key, removed_val)
        return self.MRU_ptr.val

    def put(self, key: int, value: int) -> None:
        if key in self.storage_map: self.remove(key)
        elif self.available_space <= 0: self.remove(self.storage.next.key)
        else: self.available_space -= 1
        self.insert_tail(key=key, val=value)