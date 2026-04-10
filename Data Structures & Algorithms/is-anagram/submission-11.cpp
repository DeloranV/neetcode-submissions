class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        std::map<const char, int> s_map {};
        std::map<const char, int> t_map {};

        for (int i = 0; i < s.size(); ++i) {
            if (s_map.find(s[i]) == s_map.end()) s_map[s[i]] = 1;
            else s_map[s[i]] += 1;

            if (t_map.find(t[i]) == t_map.end()) t_map[t[i]] = 1;
            else t_map[t[i]] += 1;
        }

        return (s_map == t_map);
    }
};
