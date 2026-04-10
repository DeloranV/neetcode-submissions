class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row_map = defaultdict(list)
        column_map = defaultdict(list)
        box_map = defaultdict(list)

        for i in range(9):
            for j in range(9):
                if board[i][j] == ".": continue
                if (board[i][j] in row_map[i]
                    or board[i][j] in column_map[j]
                    or board[i][j] in box_map[(i // 3, j // 3)]): 
                    return False
                row_map[i].append(board[i][j])
                column_map[j].append(board[i][j])
                box_map[(i // 3, j // 3)].append(board[i][j])
        
        return True