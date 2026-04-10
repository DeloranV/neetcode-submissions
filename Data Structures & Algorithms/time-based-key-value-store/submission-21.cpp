class TimeMap {
public:
    TimeMap() 
        : storage_()
    {}
    
    void set(string key, string value, int timestamp) {
        storage_[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (storage_.find(key) == storage_.end()) return "";
        int l, r;
        l = 0;
        r = storage_[key].size() - 1;
        if (timestamp < storage_[key][l].first) return "";
        string result;

        while (l <= r) {
            int midIdx = l + ((r - l) + 1) / 2;
            if (timestamp < storage_[key][midIdx].first) r = midIdx - 1;
            else if (timestamp > storage_[key][midIdx].first) {
                result = storage_[key][midIdx].second;
                l = midIdx + 1;
            } 
            else return storage_[key][midIdx].second;
        }
        return result;
    }

private:
    map<string, vector<pair<int, string>>> storage_;
};
