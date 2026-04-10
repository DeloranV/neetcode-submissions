class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int j = i;
            int curr = nums[i];

            while (j > 0 && curr < nums[j - 1]) {
                nums[j] = nums[j - 1];
                j--;
            }
            nums[j] = curr;
        }

        return nums;
    }
};