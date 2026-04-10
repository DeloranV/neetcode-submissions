class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;

        int prefix = 1;
        for (auto& num : nums) {
            result.push_back(prefix);
            prefix *= num;
        }

        int postfix = 1;
        for (int i = result.size() - 1; i >= 0; --i) {
            result[i] *= postfix;
            postfix *= nums[i];
        }

        return result;
    }
};
