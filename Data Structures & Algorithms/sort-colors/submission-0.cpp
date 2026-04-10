class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int j = i;
            int curr = nums[i];

            while (j > 0 && nums[j - 1] > curr) {
                nums[j] = nums[j - 1];
                j--;
            }
            nums[j] = curr;
        }
    }
};