class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() < 2) return (nums[0] == target) ? 0 : -1;
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            if (nums[l] == target) return l;
            else if (nums[r] == target) return r;
            int mid_idx = l + (r - l / 2);
            if (nums[mid_idx] == target) return mid_idx;
            else if (nums[mid_idx] < target) l = mid_idx + 1;
            else r = mid_idx - 1;
        }
        return -1;
    }
};
