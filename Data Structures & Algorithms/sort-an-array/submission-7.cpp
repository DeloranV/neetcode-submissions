class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int curr = nums[i];
            int j = i;
            
            while (j > 0 && nums[j - 1] > curr) {
                nums[j] = nums[j - 1];
                j--;
            }
            nums[j] = curr;
        }
        return nums;
    }
};