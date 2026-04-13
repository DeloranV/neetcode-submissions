class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() < 2) return target <= nums[0] ? 0 : 1;
        int max_elem = *max_element(nums.begin(), nums.end());
        if (max_elem < target) return nums.size();
        int l = 0; int r = nums.size() - 1;

        while (l <= r) {
            int midIdx = (l + r) / 2;
            if (nums[l] == target) return l;
            else if (nums[r] == target) return r;

            if (r - l == 1) {
                if (nums[l] > target) return l;
                return r;
            }
            else if (r - midIdx == 1 && midIdx - l == 1) {
                if (target > nums[l] && target < nums[midIdx]) return midIdx;
                else if (target > nums[midIdx] && target < nums[r]) return r;
                else if (target > nums[r]) return r;
            }

            if (nums[midIdx] < target) l = midIdx + 1;
            else if (nums[midIdx] > target) r = midIdx;
            else return midIdx;
        }

        return r;
    }
};