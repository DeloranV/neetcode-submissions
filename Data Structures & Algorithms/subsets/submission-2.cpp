class Solution {
public:
    void backtrack(vector<int>& nums, vector<bool>& is_used, int start_idx) {
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = start_idx; i <= nums.size(); ++i) {
            if (i == nums.size()) {
                result.push_back(temp);
                continue;
            } 
            if (!is_used[i]) {
                temp.push_back(nums[i]);
                is_used[i] = true;
                backtrack(nums, is_used, i + 1);
                is_used[i] = false;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<bool> is_used(nums.size(), false);
        backtrack(nums, is_used, 0);
        return result;
    }

    vector<int> temp;
    vector<vector<int>> result;
};
