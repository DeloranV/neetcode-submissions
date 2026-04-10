class Solution {
public:
    void backtrack(vector<int>& nums, int target, int startIdx) {
        if (temp_sum >= target) {
            if (temp_sum == target) result.push_back(temp);
            return;
        }

        for (int i = startIdx; i < nums.size(); ++i) {
            if (i != startIdx && nums[i - 1] == nums[i]) continue;
            temp.push_back(nums[i]);
            temp_sum += nums[i];
            backtrack(nums, target, i + 1);
            temp_sum -= nums[i];
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ranges::sort(candidates);
        backtrack(candidates, target, 0);
        return result;
    }

    vector<vector<int>> result;
    vector<int> temp;
    int temp_sum = 0;
};
