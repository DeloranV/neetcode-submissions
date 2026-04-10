class Solution {
public:
    void backtrack(vector<vector<char>>& board, string word, vector<vector<bool>>& is_used, pair<int, int> letterIdx, int wordIdx) {
        if (wordIdx == word.size() - 1) {
            found = true;
            return;
        }

        for (int i = 0; i < 4; ++i) {
            auto choice = resolveChoice(letterIdx, i);
            if ((choice.first >= 0 && choice.first < board.size()) &&
            (choice.second >= 0 && choice.second < board[0].size())) 
            {
                if (board[choice.first][choice.second] == word[wordIdx + 1] && !is_used[choice.first][choice.second]) {
                    is_used[choice.first][choice.second] = true;
                    wordIdx++;
                    backtrack(board, word, is_used, choice, wordIdx);
                    wordIdx--;
                    is_used[choice.first][choice.second] = false;
                }
            }
        }
    }

    vector<pair<int, int>> findFirstLetters(vector<vector<char>>& board, string word) {
        vector<pair<int, int>> result;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) result.push_back({i, j});
            }
        }
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() * board[0].size() < word.size()) return false;
        vector<bool> row(board[0].size(), false);
        vector<vector<bool>> is_used(board.size(), row);
        auto firstLetters = findFirstLetters(board, word);
        for (auto& l : firstLetters) backtrack(board, word, is_used, l, 0);

        return found;
    }

    bool found = false;

    // pair<row, col>
    pair<int, int> resolveChoice(pair<int, int> letterIdx, int choice) {
        switch(choice) {
            case 0:
            return {letterIdx.first - 1, letterIdx.second};
            break;
            case 1:
            return {letterIdx.first, letterIdx.second + 1};
            break;
            case 2:
            return {letterIdx.first + 1, letterIdx.second};
            break;
            case 3:
            return {letterIdx.first, letterIdx.second - 1};
            break;
            default: break;
        }
    }
};
