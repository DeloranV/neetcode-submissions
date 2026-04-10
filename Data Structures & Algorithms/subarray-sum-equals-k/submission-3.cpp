class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int l, r;
        l = 0;

        int counter = 0;
        while (l < nums.size()) {
            r = l;
            int running_sum = 0;
            while (r < nums.size()) {
                running_sum += nums[r++];
                if (running_sum == k) counter++;
            }
            l++;
        }
        return counter;
    }
};