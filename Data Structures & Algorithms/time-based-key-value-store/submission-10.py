class TimeMap:

    def __init__(self):
        self.store = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.store[key].append([timestamp, value])

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.store or self.store[key][0][0] > timestamp: return ""
        entry = self.store[key]
        l, r = 0, len(entry) - 1
        middle_idx = 0
        
        while l < r:
            middle_idx = l + int((r - l) / 2)
            if entry[middle_idx][0] > timestamp: r = middle_idx - 1
            else: l = middle_idx + 1
        # When exact timestamp is not present binary search will end up (l == r) either on 1st smaller or higher val
        most_recent_timestamp = l if entry[l][0] <= timestamp else l - 1    
        return entry[most_recent_timestamp][1]