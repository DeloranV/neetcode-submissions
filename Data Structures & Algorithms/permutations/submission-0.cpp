class Solution {
public:
    void backtrack(vector<int>& nums) {
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (find(curr_used.begin(), curr_used.end(), nums[i]) == curr_used.end()) {
                temp.push_back(nums[i]);
                curr_used.push_back(nums[i]);
                backtrack(nums);
                temp.pop_back();
                curr_used.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums);
        return result;
    }

    vector<int> temp;
    vector<int> curr_used;
    vector<vector<int>> result;
};
