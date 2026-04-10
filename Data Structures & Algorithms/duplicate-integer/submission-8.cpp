class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> elements;
        for (auto& num : nums) {
            if (!elements.insert(num).second) return true;
        }
        return false;
    }
};