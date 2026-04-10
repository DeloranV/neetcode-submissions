class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        unordered_set<char> unique_chars;

        int l = 0, r = 0;
        while (r < s.size()) {
            if (unique_chars.find(s[r]) == unique_chars.end()) unique_chars.insert(s[r++]);
            else unique_chars.erase(s[l++]);
            max_length = max(max_length, r - l);
        }
        return max_length;
    }
};
