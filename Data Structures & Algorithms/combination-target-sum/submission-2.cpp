class Solution {
public:
    void backtrack(vector<int>& nums, int target) {
    int sum = 0;
    for (auto& t : temp) sum += t;
    if (sum >= target) {
        if (sum == target && find(counters.begin(), counters.end(), temp_counter) == counters.end()) {
             result.push_back(temp);
             counters.push_back(temp_counter);
        }
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        temp.push_back(nums[i]);
        temp_counter[nums[i]]++;
        backtrack(nums, target);
        temp_counter[nums[i]]--;
        temp.pop_back();
    }
}

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        for (auto& num : nums) {
            temp_counter[num] = 0;
        }
        backtrack(nums, target);
        return result;
    }

    vector<unordered_map<int, int>> counters;
    unordered_map<int, int> temp_counter;
    vector<int> temp;
    vector<vector<int>> result;
};
