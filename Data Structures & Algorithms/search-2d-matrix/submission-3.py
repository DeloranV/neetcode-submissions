class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        t, b = 0, len(matrix) - 1
        l, r = 0, len(matrix[0]) - 1
        
        while t <= b:
            middle_row = t + int((b - t) / 2)
            if target >= matrix[middle_row][l] and target <= matrix[middle_row][r]:
                while l <= r:
                    middle_col = l + int((r - l) / 2)
                    if matrix[middle_row][middle_col] < target: l = middle_col + 1
                    elif matrix[middle_row][middle_col] > target: r = middle_col - 1
                    else: return matrix[middle_row][middle_col] == target
            elif target < matrix[middle_row][l]: b = middle_row - 1
            else: t = middle_row + 1

        return False