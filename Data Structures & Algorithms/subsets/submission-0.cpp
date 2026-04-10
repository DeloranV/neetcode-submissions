class Solution {
public:
    void dfs(vector<int>& nums, size_t i) {
        if (i >= nums.size()) {
            result_.push_back(subset_);
            return;
        }

        subset_.push_back(nums[i]);
        dfs(nums, i + 1);

        subset_.pop_back();
        dfs(nums, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return result_;
    }

private:
    vector<vector<int>> result_;
    vector<int> subset_;
};
