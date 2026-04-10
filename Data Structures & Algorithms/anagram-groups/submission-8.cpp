#include <array>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<array<int, 26>, vector<string>> anagram_groups;

        for (auto& s : strs) {
            array<int, 26> s_counter {};
            for (auto& c : s) s_counter[c - 97]++;
            anagram_groups[s_counter].push_back(s);
        }
        for (auto& group : anagram_groups) {
            result.push_back(group.second);
        }
        return result;
    }
};
