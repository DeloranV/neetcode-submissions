class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> unique {};
        for (auto& num : nums) {
            if (unique.find(num) != unique.end()) return true;
            unique.insert(num);
        }
        return false;
    }
};