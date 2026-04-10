class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        unordered_map<int, int> counter;

        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.second < p2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> sorted_counter;
        
        for (auto& num : nums) counter[num]++;
        for (auto& p : counter) sorted_counter.push(p);
        while (!sorted_counter.empty() && sorted_counter.top().second > (nums.size() / 3)) {
            result.push_back(sorted_counter.top().first);
            sorted_counter.pop();
        }
    
        return result;
    }
};