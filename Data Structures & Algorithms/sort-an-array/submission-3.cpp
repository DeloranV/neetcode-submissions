class Solution {
public:
    void merge(vector<int>& nums, int begin, int mid, int end) {
        int p = begin;
        int q = mid + 1;
        vector<int> temp;

        for (int i = 0; i <= end - begin; ++i) {
            if (p > mid) temp.push_back(nums[q++]);
            else if (q > end) temp.push_back(nums[p++]);
            else if (nums[p] <= nums[q]) temp.push_back(nums[p++]);
            else if (nums[p] > nums[q]) temp.push_back(nums[q++]);
        }
        int k = begin;
        for (auto& num : temp) nums[k++] = num;
    }

    void mergeSort(vector<int>& nums, int begin, int end) {
        if (begin < end) {
            int mid = begin + (end - begin) / 2;

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