class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        size_t min_str_size = numeric_limits<size_t>::max();
        for (auto& str : strs) {
            if (str.empty()) return "";
            min_str_size = min(str.size(), min_str_size);
        } 

        int i = 0;
        char curr;
        while (i < min_str_size) {
            curr = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != curr) {
                    return strs[j].substr(0, i);
                }
            }
            i++;
        }
        return strs[0].substr(0, min_str_size);
    }
};