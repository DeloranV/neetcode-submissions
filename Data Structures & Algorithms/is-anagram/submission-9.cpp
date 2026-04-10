class Solution {
public:
    bool isAnagram(string s, string t) {
        std::map<const char, int> s_map {};
        std::map<const char, int> t_map {};

        for (auto& c : s) {
            auto c_count = s_map.find(c);
            if (c_count == s_map.end()) s_map[c] = 1;
            else c_count->second += 1;
        }

        for (auto& c : t) {
            auto c_count = t_map.find(c);
            if (c_count == t_map.end()) t_map[c] = 1;
            else c_count->second += 1;
        }

        return (s_map == t_map);
    }
};
