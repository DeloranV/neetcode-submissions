class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end(), less<int>{});
        for (int i = 1; i < k; ++i) nums.pop_back();
        return nums.back();
    }
};
