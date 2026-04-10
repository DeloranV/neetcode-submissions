class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> unique; 
        int l, r;
        l = r = 0;

        while (r - l + 1 <= k) {
            if (unique.find(nums[r]) != unique.end()) return true;
            unique.insert(nums[r++]);
        } 

        while (r < nums.size()) {
            if (unique.find(nums[r]) != unique.end()) return true;
            unique.insert(nums[r++]);
            unique.erase(nums[l++]);
        }
        return false;
    }
};