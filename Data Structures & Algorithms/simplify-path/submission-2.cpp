class Solution {
public:
    string simplifyPath(string path) {
        string result;
        vector<string> s_stack;

        string temp_buf;
        for (int i = 0; i <= path.size(); ++i) {
            if (i == path.size() || path[i] == '/') {
                if (!temp_buf.empty()) {
                    if (temp_buf == "..") {
                        if(!s_stack.empty()) s_stack.pop_back();
                    } 
                    else if (temp_buf == ".") {}
                    else s_stack.push_back(temp_buf);
                } 
                temp_buf.clear();
            }
            else if (isalpha(path[i]) || path[i] == '_' || path[i] == '.') temp_buf.push_back(path[i]);
        }

        if (s_stack.empty()) result.push_back('/');
        for (auto& s : s_stack) {
            result.push_back('/');
            for (auto& c : s) result.push_back(c);
        }
        return result;
    }
};