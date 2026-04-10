class Solution {
public:
    void dfs(vector<int>& nums, int i, int target) {
        if (accumulate(combination_.begin(), combination_.end(), 0) > target || i >= nums.size()) return;
            
        if (accumulate(combination_.begin(), combination_.end(), 0) == target) {
            result_.push_back(combination_);
            return;
        }

        combination_.push_back(nums[i]);
        dfs(nums, i, target);

        combination_.pop_back();
        dfs(nums, i + 1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(nums, 0, target);
        return result_;
    }

private:
    vector<int> combination_;
    vector<vector<int>> result_;
};
