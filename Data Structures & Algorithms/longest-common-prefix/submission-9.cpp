class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_size = numeric_limits<int>::max();
        string shortest_str;
        for (auto& str : strs) {
            if (str.size() < min_size) {
                min_size = str.size();
                shortest_str = str;
            }
        } 
        
        for (int i = 0; i < min_size; ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[0][i] != strs[j][i]) return strs[0].substr(0, i);
            }
        }
        return shortest_str;
    }
};