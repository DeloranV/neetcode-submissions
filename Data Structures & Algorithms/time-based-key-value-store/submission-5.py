class TimeMap:

    def __init__(self):
        self.store = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.store[key].append([timestamp, value])

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.store: return ""
        entry = self.store[key]
        l, r = 0, len(entry) - 1
        res_timestamp = 0
        middle_idx = 0
        
        while l <= r:
            middle_idx = l + int((r - l) / 2)
            if l == r == middle_idx: break
            if entry[middle_idx][0] > timestamp: r = middle_idx - 1
            elif entry[middle_idx][0] <= timestamp: l = middle_idx + 1
        most_recent_timestamp = l if entry[l][0] <= timestamp else l - 1 #l if len(entry) % 2 != 0 else l - 1
        return entry[most_recent_timestamp][1] if entry[most_recent_timestamp][0] <= timestamp else ""