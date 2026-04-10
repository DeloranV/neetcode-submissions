class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto last = std::unique(nums.begin(), nums.end());
        int k = 0; auto beg = nums.begin();
        while (beg++ != last) k++;

        return k;
    }
};