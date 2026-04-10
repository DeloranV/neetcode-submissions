class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        vector<int> prefix_products;
        vector<int> postfix_products;

        int prefix = 1;
        int postfix = 1;
        int j = nums.size() - 1;
        for (int i = 0; i < nums.size(); ++i) {
            prefix_products.push_back(prefix);
            postfix_products.push_back(postfix);
            prefix *= nums[i];
            postfix *= nums[j--];
        }

        j = nums.size() - 1;
        for (int i = 0; i < nums.size(); ++i) {
            result.push_back(prefix_products[i] * postfix_products[j--]);
        }

        return result;
    }
};
