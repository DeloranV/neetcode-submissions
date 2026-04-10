class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l, r;
        l = 0;
        r = nums.size() - 1;

        while (l <= r) {
            int midIdx = l + ((r - l + 1) / 2);
            if (nums[midIdx] == target) return midIdx;
            else if (nums[l] == target) return l;
            else if (nums[r] == target) return r;
            if (nums[l] <= nums[midIdx]) {
                if (target < nums[l]) l = midIdx + 1;
                else r = midIdx - 1;
            }
            else if (nums[r] > nums[midIdx]) {
                if (target > nums[r] || target < nums[midIdx]) r = midIdx - 1;
                else l = midIdx + 1;
            }
            else return -1;
        }
        return -1;
    }
};
