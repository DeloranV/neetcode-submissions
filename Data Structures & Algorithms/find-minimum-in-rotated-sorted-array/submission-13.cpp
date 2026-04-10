class Solution {
public:
    int findMin(vector<int> &nums) {
        int l, r;
        int min = std::numeric_limits<int>::max();
        l = 0;
        r = nums.size() - 1;
        if (nums[l] < nums[r]) return nums[0];

        while (l <= r) {            
            int midIdx = l + ((r - l + 1) / 2);
            if ((nums[l] < nums[midIdx]) && (nums[midIdx] < nums[r])) return nums[l];
            min = std::min({min, nums[midIdx], nums[l], nums[r]});
            if (nums[r] <= nums[midIdx]) l = midIdx + 1;
            else if (nums[l] > nums[midIdx]) r = midIdx - 1;
        }
        return min;
    }
};
