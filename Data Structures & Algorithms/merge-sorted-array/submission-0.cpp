class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        int n1, n2;
        n1 = n2 = 0;

        while (temp.size() < nums1.size()) {
            if (m <= 0) temp.push_back(nums2[n2++]);
            else if (n <= 0) temp.push_back(nums1[n1++]);
            else if (nums1[n1] <= nums2[n2]) {
                temp.push_back(nums1[n1++]);
                m--;
            } 
            else {
                temp.push_back(nums2[n2++]);
                n--;
            } 
        }
        for (int i = 0; i < temp.size(); ++i) nums1[i] = temp[i];
    }
};