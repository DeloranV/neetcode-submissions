class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result {};
        map<map<const char, int>, vector<string>> anagram_groups {};

        for (auto& s : strs) {
            map<const char, int> s_counter {};
            for (auto& c : s) {
                auto c_count = s_counter.find(c);
                if (c_count != s_counter.end()) c_count->second += 1;
                else s_counter[c] = 1;
            }
            auto group = anagram_groups.find(s_counter);
            if (group != anagram_groups.end()) group->second.push_back(s);
            else anagram_groups[s_counter] = {s};
        }
        for (auto& group : anagram_groups) {
            result.push_back(group.second);
        }
        return result;
    }
};
