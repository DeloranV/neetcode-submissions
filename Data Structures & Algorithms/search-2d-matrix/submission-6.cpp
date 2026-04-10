class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int u, d, l, r;
        u = l = 0;
        d = matrix.size() - 1;
        r = matrix[0].size() - 1;

        while (u <= d) {
            int midRow = u + ((d - u + 1) / 2);
            if (target < matrix[midRow][0]) d = midRow - 1;
            else if (target > matrix[midRow][r]) u = midRow + 1;
            if (matrix[midRow][0] <= target && matrix[midRow][r] >= target) {
                while (l <= r) {
                    int midCol = l + ((r - l + 1) / 2);
                    if (target < matrix[midRow][midCol]) r = midCol - 1;
                    else if (target > matrix[midRow][midCol]) l = midCol + 1;
                    if (matrix[midRow][midCol] == target) return true;
                }
            }
        }
        return false;
    }
};
