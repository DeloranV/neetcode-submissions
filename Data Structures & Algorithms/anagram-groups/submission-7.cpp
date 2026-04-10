class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<map<char, int>, vector<string>> anagram_groups;

        for (auto& s : strs) {
            map<char, int> s_counter;
            for (auto& c : s) s_counter[c]++;
            anagram_groups[s_counter].push_back(s);
        }
        for (auto& group : anagram_groups) {
            result.push_back(group.second);
        }
        return result;
    }
};
