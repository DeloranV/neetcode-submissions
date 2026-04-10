class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> unique;
        for (auto& num : nums) unique.insert(num);

        int k = unique.size();
        int i = 0;
        for (auto& un : unique) nums[i++] = un;

        return k;
    }
};