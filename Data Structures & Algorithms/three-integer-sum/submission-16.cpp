class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> result_unique;
        
        for (int target = 0; target < nums.size(); ++target) {
            vector<int> remainders;
            for (int val1 = target + 1; val1 < nums.size(); ++val1) {
                auto needed = -nums[target] - nums[val1];
                if (find(remainders.begin(), remainders.end(), needed) == remainders.end()) remainders.push_back(nums[val1]);
                else {
                    vector<int> results_vec {nums[target], nums[val1], needed};
                    sort(results_vec.begin(), results_vec.end());
                    result_unique.insert(results_vec);
                }
            }
        }
        for (auto& elem : result_unique) result.push_back(elem);

        return result;
    }
};
