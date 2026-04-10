class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        int t = k;

        for (int i = 0; i < nums.size(); ++i) {
            temp[t++ % nums.size()] = nums[i];
        }
        nums = temp;
    }
};