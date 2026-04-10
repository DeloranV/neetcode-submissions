class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_size = numeric_limits<int>::max();
        int shortest_str;
        for (int i = 0; i < strs.size(); ++i) {
            if (strs[i].size() < min_size) {
                min_size = strs[i].size();
                shortest_str = i;
            }
        } 
        
        for (int i = 0; i < min_size; ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[0][i] != strs[j][i]) return strs[0].substr(0, i);
            }
        }
        return strs[shortest_str];
    }
};