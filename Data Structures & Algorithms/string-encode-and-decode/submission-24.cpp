class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for (auto& s : strs) {
            result += s;
            result += "|-";
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> decoded;

        int sub_begin_idx = 0;
        int delim_idx = 0;
        while (sub_begin_idx < s.size()) {
            delim_idx = s.find("|-", sub_begin_idx);
            auto sub = s.substr(sub_begin_idx, delim_idx - sub_begin_idx);
            decoded.push_back(sub);
            sub_begin_idx = delim_idx + 2;
        }
        return decoded; 
    }
};
