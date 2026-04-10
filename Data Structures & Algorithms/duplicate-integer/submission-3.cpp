class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> elements;
        for (auto& num : nums) {
            if (!std::get<1>(elements.insert(num))) return true;
        }
        return false;
    }
};