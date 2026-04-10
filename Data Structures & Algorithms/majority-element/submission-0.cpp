class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;

        for (auto& num : nums) counter[num]++;
        auto result = max_element(counter.begin(), counter.end(), 
            [](const pair<int, int>& p1, const pair<int, int>& p2){
                return p1.second < p2.second;
            }
        );

        return result->first;
    }
};