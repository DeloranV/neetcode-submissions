#include <stack>

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> bracket_mapping = {{')', '('}, {'}', '{'}, {']', '['}};
        stack<char> opening_brackets;

        for (auto& c : s) {
            if (bracket_mapping.find(c) == bracket_mapping.end()) opening_brackets.push(c);
            else {
                if (opening_brackets.empty() || opening_brackets.top() != bracket_mapping[c]) return false;
                opening_brackets.pop();
            }
        }
        return opening_brackets.empty();
    }
};
