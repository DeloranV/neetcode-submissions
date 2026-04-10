class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int smallest_diff = numeric_limits<int>::max();
        int total_diff = 0;
        vector<int> result(k);
        int l, r;
        l = r = 0;

        while (r < arr.size()) {
            int diff = abs(arr[r] - x);
            total_diff += diff; 
            if (r - l + 1 == k) {
                if (total_diff < smallest_diff) {
                    smallest_diff = total_diff;
                    int begin = l;
                    for (int i = 0; i < k; ++i) result[i] = arr[begin++];
                }
                total_diff -= abs(arr[l++] - x);
            }
            r++;
        }
        return result;
    }
};