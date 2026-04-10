class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> elements;
        for (auto& num : nums) {
            if (!elements.insert(num).second) return true;
        }
        return false;
    }
};