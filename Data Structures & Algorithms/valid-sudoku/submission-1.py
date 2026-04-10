class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for row in board:
            unique_row = {}
            for element in row:
                if element.isdigit():
                    unique_row[element] = unique_row.get(element, 0) + 1
            for row_occurence in unique_row.values():
                if row_occurence > 1: return False

        for i in range(9):
            unique_column = {}
            for j in range(9):
                if board[j][i].isdigit():
                    unique_column[board[j][i]] = unique_column.get(board[j][i], 0) + 1
            for col_occurence in unique_column.values():
                if col_occurence > 1: return False

        unique_square = defaultdict(list)
        for row in range(9):
            for col in range(9):
                if board[row][col].isdigit():
                    elem_square = (row // 3) * 3 + (col // 3)
                    unique_square[elem_square].append(board[row][col])

        for square in unique_square.values():
            hash_set = set()
            for num in square:
                hash_set.add(num)
            if len(hash_set) != len(square): return False
        
        return True