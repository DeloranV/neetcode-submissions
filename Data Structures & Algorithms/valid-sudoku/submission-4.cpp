class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::map<std::pair<int, int>, std::set<char>> box;

        for (int i = 0; i < 9; ++i) {
            std::set<int> row;
            std::set<int> col;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    auto row_elem = row.find(board[i][j]);
                    if (row_elem != row.end()) return false;
                    else row.insert(board[i][j]);

                    auto box_set = box.find({i / 3, j / 3});
                    if (box_set == box.end()) box[{i / 3, j / 3}].insert(board[i][j]);
                    else {
                        auto box_elem = box_set->second.find(board[i][j]);
                        if (box_elem != box_set->second.end()) return false;
                        else box_set->second.insert(board[i][j]);
                    }
                }

                if (board[j][i] != '.') {
                    auto col_elem = col.find(board[j][i]);
                    if (col_elem != col.end()) return false;
                    else col.insert(board[j][i]);
                } 
            }
        }
        return true;
    }
};
