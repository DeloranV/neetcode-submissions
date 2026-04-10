class Solution {
public:
    int partition(vector<int>& nums, int start, int end) {
        int pivot = start;
        int i = start + 1;

        for (int j = start + 1; j <= end; ++j) {
            if (nums[j] < nums[pivot]) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[pivot], nums[i - 1]);
        return i - 1;
    }

    void quickSort(vector<int>& nums, int start, int end) {
        if (start < end) {
            int pivot_idx = partition(nums, start, end);
            quickSort(nums, start, pivot_idx - 1);
            quickSort(nums, pivot_idx + 1, end);
        }
    }

    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
    }
};