class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int window_sum = 0;
        int min_length = numeric_limits<int>::max();
        int l = 0, r = 0;

        while (r < nums.size()) {
            if (window_sum >= target) {
                min_length = min(min_length, r - l);
                window_sum -= nums[l++];
            } 
            else window_sum += nums[r++];
        }
        if (window_sum >= target) min_length = min(min_length, r - l);
        
        while (l < r) {
            window_sum -= nums[l++];
            if (window_sum >= target) min_length = min(min_length, r - l);
        }

        return min_length == numeric_limits<int>::max() ? 0 : min_length;
    }
};