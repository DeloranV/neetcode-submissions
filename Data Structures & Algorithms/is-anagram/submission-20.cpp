#include <array>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        array<int, 26> s_counter {};
        array<int, 26> t_counter {};

        for (int i = 0; i < s.size(); ++i) {
            s_counter[s[i] - 97]++;
            t_counter[t[i] - 97]++;
        }
        return s_counter == t_counter;
    }
};
