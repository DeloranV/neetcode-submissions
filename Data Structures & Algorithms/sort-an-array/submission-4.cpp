class Solution {
public:
    void merge(vector<int>& nums, int begin, int mid, int end) {
        int p = begin, q = mid + 1;
        int temp[end - begin + 1]; int k = 0;

        for (int i = begin; i <= end; ++i) {
            if (p > mid) temp[k++] = nums[q++];
            else if (q > end) temp[k++] = nums[p++];
            else if (nums[p] <= nums[q]) temp[k++] = nums[p++];
            else temp[k++] = nums[q++];
        }
        for (int i = 0; i < k; ++i) nums[begin++] = temp[i];
    }

    void mergeSort(vector<int>& nums, int begin, int end) {
        if (begin < end) {
            int mid = (begin + end) / 2;
            mergeSort(nums, begin, mid);
            mergeSort(nums, mid + 1, end);
            merge(nums, begin, mid, end);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};