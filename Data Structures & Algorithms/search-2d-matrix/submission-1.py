class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        top, bottom = 0, len(matrix) - 1
        l, r = 0, len(matrix[0]) - 1

        while top <= bottom:
            middle_row = top + int((bottom - top) / 2)
            if target >= matrix[middle_row][l] and target <= matrix[middle_row][r]: 
                while l <= r:
                    middle_idx = l + int((r - l) / 2)
                    if matrix[middle_row][middle_idx] < target: l = middle_idx + 1
                    elif matrix[middle_row][middle_idx] > target: r = middle_idx - 1
                    else: return True
            elif target > matrix[middle_row][r]: top = middle_row + 1
            else: bottom = middle_row - 1
        
        return False