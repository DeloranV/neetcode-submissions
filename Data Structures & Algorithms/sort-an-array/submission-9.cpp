class Solution {
public:
    int sorting(vector<int>& nums, int begin, int end) {
        int pivotIdx = begin;
        int i = begin + 1;

        for (int j = begin + 1; j <= end; ++j) {
            if (nums[j] <= nums[pivotIdx]) {
                swap(nums[j], nums[i]);
                i++;
            }
        }
        swap(nums[i - 1], nums[pivotIdx]);
        return i - 1;
    }

    void quickSort(vector<int>& nums, int begin, int end) {
        if (begin < end) {
            int pivotIdx = sorting(nums, begin, end);
            quickSort(nums, begin, pivotIdx - 1);
            quickSort(nums, pivotIdx + 1, end);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};