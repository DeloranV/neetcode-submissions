class Solution {
public:
    void backtrack(vector<int>& nums, vector<bool>& is_used, int start_idx) {
        if (temp.size() == nums.size()) {
            if (find(counters.begin(), counters.end(), temp_counter) == counters.end()) {
                result.push_back(temp);
                counters.push_back(temp_counter);
            } 
            return;
        }

        for (int i = start_idx; i <= nums.size(); ++i) {
            if (i == nums.size()) {
                if (find(counters.begin(), counters.end(), temp_counter) == counters.end()) {
                    counters.push_back(temp_counter);
                    result.push_back(temp);
                } 
                continue;
            }
            if (!is_used[i]) {
                temp.push_back(nums[i]);
                is_used[i] = true;
                temp_counter[nums[i]]++;
                backtrack(nums, is_used, i + 1);
                temp_counter[nums[i]]--;
                is_used[i] = false;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        for (auto& n : nums) temp_counter[n] = 0;
        vector<bool> is_used(nums.size(), false);
        backtrack(nums, is_used, 0);
        return result;
    }

    vector<map<int, int>> counters;
    map<int, int> temp_counter;
    vector<int> temp;
    vector<vector<int>> result;
};
