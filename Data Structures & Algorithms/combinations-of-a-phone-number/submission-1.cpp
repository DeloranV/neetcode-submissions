class Solution {
public:
    void backtracking(string digits, vector<char>& choices, int digitIdx) {
        if (combination.size() == digits.size()) {
            result.push_back(combination);
            return;
        }

        for (int i = 0; i < choices.size(); ++i) {
            combination.push_back(choices[i]);
            backtracking(digits, digit_mapping[digits[digitIdx + 1]], digitIdx + 1);
            combination.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        backtracking(digits, digit_mapping[digits[0]], 0);
        return result;
    }

    map<char, vector<char>> digit_mapping {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}},
        };

    string combination;
    vector<string> result;
};
