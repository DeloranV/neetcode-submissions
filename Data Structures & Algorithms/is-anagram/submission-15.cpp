class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        std::map<const char, int> s_map;
        std::map<const char, int> t_map;

        for (int i = 0; i < s.size(); ++i) {
            auto s_map_it = s_map.find(s[i]);
            if (s_map_it == s_map.end()) s_map[s[i]] = 1;
            else s_map_it->second += 1;
            
            auto t_map_it = t_map.find(t[i]);
            if (t_map_it == t_map.end()) t_map[t[i]] = 1;
            else t_map_it->second += 1;
        }
        return (s_map == t_map);
    }
};
