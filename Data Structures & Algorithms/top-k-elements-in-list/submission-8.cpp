class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        vector<vector<int>> freq_counter(nums.size() + 1);
        vector<int> result;

        for (auto& num : nums) counter[num]++;
        for (auto& num_pair : counter)
            freq_counter[num_pair.second].push_back(num_pair.first);
    
        auto freq_it = --freq_counter.end();
        while (k > 0) {
            while (freq_it->size() == 0) --freq_it;
            for (auto& elem : *freq_it) {
                result.push_back(elem);
                --k;
            }
            --freq_it;
        }
        return result;
    }
};
