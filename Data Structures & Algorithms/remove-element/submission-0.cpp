class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int k = 0;

        for (auto& num : nums) 
            if (num != val) nums[k++] = num;
        
        return k;
    }
};