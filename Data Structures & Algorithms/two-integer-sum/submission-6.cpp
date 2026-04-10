class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> remainders;

        for (int i = 0; i < nums.size(); ++i) {
            auto needed = target - nums[i];
            auto remainder = remainders.find(needed);
            if (remainder != remainders.end()) return {remainder->second, i};
            remainders[nums[i]] = i;
        }
    }
};
