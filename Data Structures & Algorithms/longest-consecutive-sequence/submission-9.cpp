class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 0) return 0;
        int count;
        int max_count = std::numeric_limits<int>::min();

        std::unordered_set<int> nums_set;
        for (auto& n : nums) nums_set.insert(n);
        
        std::vector<int> seq_start;
        for (auto& n : nums_set) {
            if (nums_set.find(n - 1) == nums_set.end()) seq_start.push_back(n);
        }

        for (auto& num : seq_start) {
            count = 1;
            int curr_num = num;
            while (nums_set.find(curr_num + 1) != nums_set.end()) {
                count++;
                curr_num = *nums_set.find(curr_num + 1);
            }
            max_count = std::max(max_count, count);
        }

        return max_count;
    }
};
